#!/bin/bash
gcc csv.cpp -o csv.so -Iinclude/divdx/ -fPIC -funsigned-char -fpermissive -w -shared -O1
