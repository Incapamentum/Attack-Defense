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

    echo "Spy process will execute on core ${1}..."
    echo ""

    echo "Executing..."
    while true; do taskset -c $1 ./spy/primeprobe_spy 1000 > /dev/null; done &

    echo "Executing quickhpc at resolution of 1ms..."
    echo ""

    echo "Collecting quickhpc information..."
    ./quickhpc/quickhpc -a %1 -n $3 -i 10 -c $2 > ./hpc_data/spy_hpc.txt
    pkill primeprobe_spy
    echo "Complete"

else
    echo "Not a valid core number!"
    exit 2
fi