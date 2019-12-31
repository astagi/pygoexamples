#!/bin/bash

gcc -shared -o newmath.so `pkg-config --cflags --libs python3` `python3-config --libs --embed` newmath.c
