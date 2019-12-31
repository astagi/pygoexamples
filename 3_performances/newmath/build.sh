#!/bin/bash

rm *.so
rm *.h
rm *.a

go build -buildmode=c-archive -o libnewmath.a

gcc _newmath.c -shared -o newmath.so `pkg-config --cflags --libs python3` `python3-config --libs --embed` -L . -lnewmath
