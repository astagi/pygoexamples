#!/bin/bash

gcc -shared -o newmath.so `pkg-config --cflags --libs python3` newmath.c
