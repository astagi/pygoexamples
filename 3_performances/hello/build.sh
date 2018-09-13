#!/bin/bash

rm *.so
rm *.h
rm *.a

go build -buildmode=c-archive -o libhello.a hello.go

gcc hello.c -shared -o hello.so `pkg-config --cflags --libs python3` -L . -lhello