#!/bin/bash

if [[ $# -ne 4 ]]; then
    echo "Illegal number of parameters!"
    echo ""
    echo "Usage: ${0} [core] [exponent] [samples] [set]"
    echo "    core     - the core on which the spy and victim processes will run on"
    echo "    exponent - exponent value to be passed for the Square-Multiply Exponentiation"
    echo "    samples  - number of samples to run attack for"
    echo "    set      - cache set to monitor"
    exit 2
fi

cpu_cores=$(nproc --all)

# Ensuring CPU core is within what is available
echo "Number of cores on system:" $cpu_cores
echo ""

if [ $1 -ge 0 ] && [ $1 -lt $cpu_cores ]; then
    echo "Processes will execute on core ${1}..."
    echo ""

    echo "Executing victim..."
    while true; do taskset -c $1 ./victim/square_multiply/victim_sqr_mult $2; done & echo "PID Of victim process:" $!
    victim=$!
    echo ""

    echo "Waiting to execute spy..."
    sleep 5s

    echo "Executing calibration..."
    taskset -c $1 ./calibration/primeprobe_calibrate $3 $4 > ./calibration/trace.txt
    echo "Spy has completed."
    echo "Killing victim process..."
    kill $victim
    echo "Completed!"
else
    echo "Not a valid core number!"
    exit 2
fi