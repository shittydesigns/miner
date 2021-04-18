#pragma once
#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
#include <string>

using namespace eosio;
class [[eosio::contract]] whale : public contract {
  public:
      using contract::contract;
      [[eosio::action]]
      void payforcpu( name user ) {
      require_recipient( user );
}
      [[eosio::action]]
       void notify( name to, std::string message ) {
      require_recipient( to );
     }
      [[eosio::action]]
       void transfer( const name from,
                      const name to,
                      const asset quantity,
                      const std::string memo ) {
      require_auth(_self);
      require_recipient( from );
      require_recipient( to );
}
      [[eosio::action]]
//Make sure you include eosio.code in your active permission!!!
//Refer to http://github.com/EOSIO/eosio.cdt/issues/250 for asset information
//Loop is in uint32.
//[[eosio::action]] OR [[eosio::on_notify("Whatever token::Whatever action")]] you want to leech on

//ONLY REQUIRED WHEN IT'S AN ACTION
//      void claim() {
//      require_auth( _self );

       void claim( const name from,
                   const name to,
                   const asset quantity,
                   const std::string memo ) {


//Don't fuck yourself up in using on_notify!
//Only USE IT WHEN YOU HAVE NAME FROM AND TO!!! OR AN ERROR WOULD BE THROWN!
      if (to != get_self() || from == get_self()) return;

//I don't think the rest need explination, i <= x is the amount of time you want it
      int count = 1;
   while( count < 100 ) {
      action {
                      permission_level{get_self(), "active"_n},
                      "eosio.token"_n, "transfer"_n,
                      std::make_tuple(get_self(), "eosiopowcoin"_n, asset(1,symbol("EOS", 4)), std::string(""))
      }.send();
      count++;
};
}
};
