#!/bin/bash
while true
do
cleos -u https://eos.newdex.one:443 push action iamawhale.m claim '["90"]' -p iamawhale.m@cosign --expiration 1800 --max-cpu-usage-ms 24
read -t 20 -p "I am going to wait for 20 seconds only ..."
done
