# How to execute and compile the code

## Important before you start
You need have installed the following tools:
- bash
- gcc (c++11)
- Succint Data Structure Library (SDSL) (github.com/simongog/sdsl-lite)

First argument is the name of the file to compile 
Second argument is the name of the executable and the third is the directory where the lib is installed

if its not provided the directory of the lib use sdsl-lite as default or 
or use a environment variable called SDSL_DIR to set the directory of the lib

If the first argument is -d compile all the programs in the directory
all the executable will be has the extension .out and will be in the bin directory

create the bin directory in the current directory if it does not exist 
remind this script will be in any directory you want to compile the program

## Example
./compile.sh <main_file_name> <output_file_name> <sdsl_dir>
