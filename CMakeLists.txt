cmake_minimum_required(VERSION 3.26)
project(DA2324_PRJ1_G13_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DA2324_PRJ1_G13_4
        main.cpp
        src/City.cpp
        src/City.h
        src/Reservoir.cpp
        src/Reservoir.h
        src/Station.cpp
        src/Station.h
        src/Graph.h
        src/Graph.cpp
        src/csvInfo.h
        src/csvInfo.cpp
        src/AuxFunctions.cpp
        src/AuxFunctions.h
)
