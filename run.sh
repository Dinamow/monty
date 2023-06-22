#!/usr/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
./monty test.m
echo "--------------------"
valgrind ./monty test.m
echo $?
