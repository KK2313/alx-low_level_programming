#!/bin/bashgcc -Wall -Werror -Wextra -pedantic -c *.c
ar -rc liball.a *.o
ranlib liball.a
