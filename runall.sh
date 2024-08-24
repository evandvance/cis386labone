#!/bin/bash

gcc ./src/triangleinfo.c -o ./bin/triangleinfo.exe
gcc ./src/ispalindrome.c -o ./bin/ispalindrome.exe
gcc ./src/ispowerful.c -o ./bin/ispalindrome.exe

./bin/ispalindrome.exe
./bin/ispowerful.exe
./bin/triangleinfo.exe