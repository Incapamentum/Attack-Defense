#!/bin/bash

# ===================
#     DESCRIPTION
# ===================
#     Runs both the spy and victim processes on the same core.
#     Captures the cache traces generated by the spy. Once
#     completed, the victim process is then killed.
#

if [[ $# -ne 2 ]]; then
    echo "Illegal number of parameters!"
    echo ""
    echo "Usage: ${0} [core] [samples]"
    echo "    core    - the core on which the spy and victim processes will run on"
    echo "    samples - number of samples to run attack for"
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
    while true; do taskset -c $1 ./victim/square_multiply/victim_sqr_mult; done & echo "PID of victim process:" $!
    echo ""

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