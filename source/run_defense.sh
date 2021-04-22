#!/bin/bash

if [[ $# -ne 3 ]]; then
    echo "Illegal number of parameters!"
    echo ""
    echo "Usage: ${0} [core] [event_path] [iterations]"
    echo "      core       - core on which spy/victim processes will be executed on"
    echo "      event_path - name of the path pointing to events.conf file"
    echo "      iterations - number of iterations to run quickhpc for"
    exit 2
fi

cpu_cores=$(nproc --all)

echo "Number of cores on system:" $cpu_cores
echo ""

# Ensuring CPU core is within what is available
if [ $1 -ge 0 ] && [ $1 -lt $cpu_cores ]; then
    echo "Processes will execute on core ${1}..."
    echo ""

    echo "Executing victim..."
    while true; do taskset -c $1 ./victim/square_multiply/victim_sqr_mult; done & echo "PID of victim process:" $!
    victim=$!
    echo ""

    echo "Waiting to execute spy..."
    sleep 5s

    echo "Executing spy..."
    while true; do taskset -c $1 ./spy/primeprobe_spy 1000 > /dev/null; done & echo "PID of spy process:" $!
    spy=$!

    echo "Executing quickhpc at resolution of 1ms..."
    echo ""

    echo "Collecting information on victim process..."
    ./quickhpc/quickhpc -a $victim -n 1000 -i $3 -c $2 > ./hpc_data/victim_hpc.txt
    echo "Complete"
    echo ""

    echo "Collecting information on spy process..."
    ./quickhpc/quickhpc -a $spy -n 1000 -i $3 -c $2 > ./hpc_data/spy_hpc.txt
    echo "Complete"
    echo ""

    echo "Killing processes..."
    kill $victim
    kill $spy
    echo ""

    echo "Completed!"
else
    echo "Not a valid core number!"
    exit 2
fi