#!/bin/sh

curl -i -s $1 | grep 'location' | awk '{printf "%s\n", $2}'
