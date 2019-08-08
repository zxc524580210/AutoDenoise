# 查找当前目录下的所有源文件
cmake_minimum_required(VERSION 3.9)
project(VideoDenoise)
set(CMAKE_CXX_STANDARD 11)
# 并将名称保存到 DIR_LIB_SRCS 变量

add_subdirectory(libNS)
# 指定生成 libNS 链接库
include_directories(libNS)

# 指定生成 libAgAGC 链接库
include_directories(re_sampler)
link_directories("re_sampler")

add_subdirectory(libAGC)
# 指定生成 libAgAGC 链接库
include_directories(libAGC)

# 指定 MathFunctions 库的安装路径
add_executable(AudioDenoise main.cpp)
# 添加链接库
target_link_libraries(AudioDenoise AgNS AgAGC resampler)
