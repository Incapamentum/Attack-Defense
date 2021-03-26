#!/bin/bash

echo "Executing victim..."

while true; do taskset -c 7 ./victim/square_multiply/victim_sqr_mult; done