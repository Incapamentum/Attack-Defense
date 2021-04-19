#!/bin/bash

# echo [[ $# -ne 1 ]]

if [[ $# -ne 2 ]]; then
    echo "Illegal number of parameters!"
    echo ""
    echo "Usage: ./run_attack.sh [core] [samples]"
    echo "    core - the core on which the spy and victim processes will run on"
    echo "    samples - number of samples to run attack for"
    exit 2
fi

# input="$1"
cpu_cores=$(nproc --all)

echo "Number of cores on system:" $cpu_cores
echo ""

if [ $1 -ge 0 ] && [ $1 -lt $cpu_cores ]; then
    echo "Executing victim..."
    while true; do taskset -c $1 ./victim/square_multiply/victim_sqr_mult; done & echo "PID of victim process:" $!

    echo "Waiting to execute spy..."
    sleep 5s

    echo "Executing spy..."
    taskset -c $1 ./spy/primeprobe_spy $2 > ./spy/trace.txt
    echo "Spy has completed."
    echo "Killing victim process..."
    kill $!
    echo "Completed!"
else
    echo "Not a valid core number!"
    exit 2
fi