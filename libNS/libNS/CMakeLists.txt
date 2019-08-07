# 查找当前目录下的所有源文件
cmake_minimum_required(VERSION 3.9)
project(AgNS)
set(CMAKE_CXX_STANDARD 11)
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)


# 指定 MathFunctions 库的安装路径
add_library (AgNS STATIC ${DIR_LIB_SRCS})

