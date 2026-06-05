cmake_minimum_required(VERSION 3.10)
project(Lab4_PersonSystem CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

add_executable(Lab4
    src/main.cpp
    src/Person.cpp
    src/Worker.cpp
    src/Electrician.cpp
    src/PersonSystem.cpp
)

target_include_directories(Lab4 PRIVATE include)
