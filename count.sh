#!/bin/bash
#send 1 ~ 50 to server 
for ((COUNT = 1; COUNT <= 50; COUNT++)); do
  echo $COUNT
  sleep 1
done
