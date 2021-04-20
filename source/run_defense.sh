#!/bin/bash

# ????
# What am I even doing here?
if [[ $3 -ne 2 ]]; then
    echo "Illegal number of parameters!"
    echo ""
    echo "Usage: ./run_defense.sh [core] [event_list_path]"
    echo "      core            - the core oon which the spy and victim processes will execute on"
    echo "      event_list_path - path to the conf file containing PAPI events to monitor"
    exit 2
fi

