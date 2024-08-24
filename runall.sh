#!/bin/bash

gcc ./code/triangleinfo.c -o ./bin/triangleinfo.exe
gcc ./code/ispalindrome.c -o ./bin/ispalindrome.exe
gcc ./code/ispowerful.c -o ./bin/ispalindrome.exe

./bin/ispalindrome.exe
./bin/ispowerful.exe
./bin/triangleinfo.exe