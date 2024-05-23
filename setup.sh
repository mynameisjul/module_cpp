#!/bin/bash

read -p "enter module number " mod_number
mkdir -p "cpp_module_$mod_number"
cd cpp_module_$mod_number 
for i in 0 1 2 3 4 5 6
do
	mkdir ex0$i
	cd ex0$i
	mkdir src
	mkdir include
	cd src
	touch main.cpp
	cd ..
	cp -n ../../Makefile ./Makefile
	cd ..
done