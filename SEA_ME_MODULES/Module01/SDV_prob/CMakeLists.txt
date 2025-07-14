cmake_minimum_required(VERSION 3.10)
project(SDV_prob)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/Car.cpp
    src/SportsCar.cpp
    main.cpp
)

add_executable(main ${SOURCES})
