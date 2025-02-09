cmake_minimum_required(VERSION 3.16)
project(hello_qt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(hello_qt main.cpp)

target_link_libraries(hello_qt PRIVATE Qt5::Widgets -Wl,--no-as-needed -lpthread)
