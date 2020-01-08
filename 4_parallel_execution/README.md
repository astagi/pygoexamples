# Performances Chapter

This is a simple example to demonstrate how Go performs great during parallel calculations

## Build the library

    ./build.sh

## Try yourself

If you want to try the pure Python implementation, run

    python purethreads.py

Or if you want to see how it performs with multiprocessing, run

    python pureperfthreads.py

For the Go implementation run

    python threads.py

## See yourself

### Using Go

    (perf)➜ python threads.py
    Done! My final value is  0
    Done! My final value is  0
    Time taken in seconds - 0.014990091323852539

### Using threads

    (perf)➜ python purethreads.py
    Done! My final value is 0
    Done! My final value is 0
    Time taken in seconds - 5.691630840301514

### Using multiprocessing Pool

    (perf)➜ python pureperfthreads.py
    Done! My final value is 0
    Done! My final value is 0
    Time taken in seconds - 2.3557422161102295

If you want to know more about GIL, [go there](https://realpython.com/python-gil/)
