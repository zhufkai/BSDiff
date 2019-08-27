cmake_minimum_required(VERSION 3.4.1)

# 查找文件系统中制定模式的路径，如：/*是匹配根目录下的所有文件
file(GLOB bzip_source src/main/cpp/bzip/*.c)

include_directories(src/main/cpp/bzip)

# 设置本地动态库，编译生成动态库
add_library( # Sets the name of the library.
        bspatcher # 模块名
        SHARED # 动态库、分享库
        src/main/cpp/native-lib.cpp
        src/main/cpp/bspatch.c
        ${bzip_source})# 源文件

# 查找系统库，日志输出库Log
find_library( # Sets the name of the path variable.
        log-lib
        log )

# 需要链接或者编译的库
target_link_libraries( # Specifies the target library.
        bspatcher
        ${log-lib} )