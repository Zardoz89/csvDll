#!/bin/bash
gcc $1 -o $2 -fPIC -funsigned-char -fpermissive -w -shared -O1
