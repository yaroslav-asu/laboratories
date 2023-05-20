cmake_minimum_required(VERSION 3.0)
project(laboratories)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML
        COMPONENTS
        system window graphics network audio REQUIRED)

add_executable(laboratories main.cpp  1/1.cpp 2/2.cpp 3/3.cpp 4/4.cpp 5/5.cpp 6/6.cpp 6/io/input.cpp 6/io/output.cpp 9/9.cpp 10/10.cpp 8/8.cpp 11/11.cpp)

target_link_libraries(laboratories sfml-graphics sfml-audio)
