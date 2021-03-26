#!/bin/bash

taskset -c 7 ./spy/primeprobe_spy $1 > ./spy/trace.txt

echo "Spy has completed."
echo "Killing victim process..."

kill $2