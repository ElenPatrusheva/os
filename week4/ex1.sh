#!/bin/bash
gcc ex1.c -o ex1.o
for i in {1..10}
do
	./ex1.o
done
rm ex1.o
