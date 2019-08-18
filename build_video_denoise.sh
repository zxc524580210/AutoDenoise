#!/bin/bash
cd ./Videodenoise
if [ ! -d "build" ]; then
mkdir build
else
rm -rf build
mkdir build
fi
cd build
cmake ..
make
cd ../../
if [ ! -d "build" ]; then
mkdir build
else
rm -rf build
mkdir build
fi
echo "***************************"
echo "***** Build ffmpeg ! *****"
echo "***************************"
cd ./ffmpeg
./configure --prefix=../build
make clean
make && make install
echo "***************************"
echo "*** Build libNS ! **"
echo "***************************"
cd ..
cd ./libNS
if [ ! -d "build" ]; then
mkdir build
else
rm -rf build
mkdir build
fi
cd build
cmake ../
make
cd  ../../
cp  ./libNS/build/AudioDenoise ./build/bin

cp ./Videodenoise/build/Videodenoise  ./build/bin
echo "***************************"
echo "***** Build success ! *****"
echo "***************************"
