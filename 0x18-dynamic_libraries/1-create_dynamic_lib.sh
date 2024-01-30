#!/bin/bash
if [ ! -f 100-operations.c ]; then
    echo "Error: 100-operations.c not found."
    exit 1
fi
gcc -fPIC -c 100-operations.c
if [ ! -f 100-operations.o ]; then
    echo "Error: Compilation of 100-operations.c failed."
    exit 1
fi
gcc -shared -o 100-operations.so 100-operations.o
if [ ! -f 100-operations.so ]; then
    echo "Error: Creation of dynamic library failed."
    exit 1
fi
python3 100-tests.py
rm 100-operations.o
