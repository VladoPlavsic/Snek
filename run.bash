#!/bin/bash
[ -d "build/" ] || mkdir build
echo "Linking..."
cd build/ 
cmake ../
echo "Building..."
cmake --build .
echo "Finished..."
./Snek
