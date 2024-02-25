cmake_minimum_required(VERSION 3.26)
project(stringClass)

set(CMAKE_CXX_STANDARD 17)

add_executable(stringClass src/main.cpp
        src/MyString.cpp
        include/MyString.h)
