# Chapter 3 - Performances

In this chapter we analyze performaces.

## Build newmath library

    cd newmath
    ./build.sh

## Build hello library

    cd hello
    ./build.sh

## Try the new math library

    python trysum.py

## Try to say hello and see the performances

    export GODEBUG=cgocheck=0
    python try_hello.py

## Why prepend '_' to file names?

In the directory containing the package, .go, .c, .h, and .s files are considered part of the package except for:

- .go files in package documentation
- files starting with _ or . (likely editor temporary files)
- files with build constraints not satisfied by the context
