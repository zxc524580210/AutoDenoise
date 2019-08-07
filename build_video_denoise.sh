#!/bin/bash
cd Videodenoise/build
cmake ..
make
cd ..
if [ ! -d "build" ]; then
mkdir build
else
rm -rf build
mkdir build
fi
echo "***************************"
echo "***** Build ffmpeg ! *****"
echo "***************************"
cd ffmpeg
./configure --prefix=../build
make clean
make && make install
echo "***************************"
echo "*** Build libNS ! **"
echo "***************************"
cd ../libNS
if [ ! -d "build" ]; then
mkdir build
else
rm -rf build
mkdir build
fi
cd build
cmake ../
cp ./AudioDenoise ../../build/bin
echo "***************************"
echo "***** Build success ! *****"
echo "***************************"
