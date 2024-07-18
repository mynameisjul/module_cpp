#!/bin/bash

read -p "enter module number " mod_number
mkdir -p "$mod_number"CPP
cd "$mod_number"CPP
for i in 0 1 2 3 4 5 6
do
	mkdir -p ex0$i
	cd ex0$i
	mkdir src
	cd src
	touch main.cpp
	cd ..
	mkdir include
	cp -n ../../Makefile ./Makefile
	cd ..
done