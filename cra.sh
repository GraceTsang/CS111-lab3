#! /bin/bash

gcc -o ospfscrashtest ospfscrashtest.c

./ospfscrashtest 2

cd test

ln -s hello.txt slink

cd ..

./ospfscrashtest -1

ls -li test > crashed.log
