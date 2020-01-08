#!/bin/bash

rm *.so
rm perf.h
rm perf.c

go build -buildmode=c-shared -o perf.so *.go

python pygen.py > perf.c

gcc perf.c -dynamiclib perf.so -o pyperf.so `pkg-config --cflags --libs python3` `python3-config --libs --embed`
