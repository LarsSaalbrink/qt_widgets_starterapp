# cmake_minimum_required(VERSION 3.16)
# project(hello_qt)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_AUTOUIC ON)

# find_package(Qt5 COMPONENTS Widgets REQUIRED)

# add_executable(hello_qt main.cpp)
# target_link_libraries(hello_qt PRIVATE Qt5::Widgets)

cmake_minimum_required(VERSION 3.16)
project(hello_qt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add these lines to handle library paths
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "/usr/lib/x86_64-linux-gnu")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(hello_qt main.cpp)
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
# target_link_libraries(hello_qt PRIVATE Qt5::Widgets)

target_link_libraries(hello_qt PRIVATE Qt5::Widgets -Wl,--no-as-needed -lpthread)

# Force using system libraries
set_target_properties(hello_qt PROPERTIES
    INSTALL_RPATH "/usr/lib/x86_64-linux-gnu"
    BUILD_WITH_INSTALL_RPATH TRUE
)