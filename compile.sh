#!/bin/bash

#this a script to compile the program 
#with the lib for succint data structures of simongog

#First argument is the name of the file to compile 
#Second argument is the name of the executable
#and the third is the directory where the lib is installed

#if its not provided the directory of the lib use sdsl-lite as default or 
#or use a environment variable called SDSL_DIR to set the directory of the lib

#If the first argument is -d compile all the programs in the directory
# all the executable will be has the extension .out 
# and will be in the bin directory

#create the bin directory in the current directory if it does not exist 
#remind this script will be in any directory you want to compile the program

if [ ! -d "bin" ]; then
    mkdir bin
fi

if [ "$1" == "-d" ]; then
    for file in *.cpp
    do
        if [ ! -z "$3" ]; then
            g++ -std=c++11 -O3 -DNDEBUG -I$3/include $file -o bin/${file%.*}.out -L$3/lib -lsdsl -ldivsufsort -ldivsufsort64
        else
            g++ -std=c++11 -O3 -DNDEBUG -I$SDSL/include $file -o bin/${file%.*}.out -L$SDSL/lib -lsdsl -ldivsufsort -ldivsufsort64
        fi
    done
else
    if [ ! -z "$3" ]; then
        g++ -std=c++11 -O3 -DNDEBUG -I$3/include $1 -o bin/$2 -L$3/lib -lsdsl -ldivsufsort -ldivsufsort64
    else
        g++ -std=c++11 -O3 -DNDEBUG -I$SDSL/include $1 -o bin/$2 -L$SDSL/lib -lsdsl -ldivsufsort -ldivsufsort64
    fi
fi

#if [ -z "$3" ]
#then
#    if [ -z "$SDSL_DIR" ]
#    then
#        g++ -std=c++11 -O3 -DNDEBUG -I sdsl-lite/include $1 -o $2 -L sdsl-lite/lib -lsdsl -ldivsufsort -ldivsufsort64
#    else
#        g++ -std=c++11 -O3 -DNDEBUG -I $SDSL_DIR/include $1 -o $2 -L $SDSL_DIR/lib -lsdsl -ldivsufsort -ldivsufsort64
#    fi
#else
#    g++ -std=c++11 -O3 -DNDEBUG -I $3/include $1 -o $2 -L $3/lib -lsdsl -ldivsufsort -ldivsufsort64
#fi
echo "Compilation finished"
#end of script
