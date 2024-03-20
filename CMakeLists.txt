cmake_minimum_required(VERSION 3.26)
project(DA2324_PRJ1_G13_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DA2324_PRJ1_G13_4
        main.cpp
        City.cpp
        City.h
        Reservoir.cpp
        Reservoir.h
        Station.cpp
        Station.h
        Graph.h
        Graph.cpp
        csvInfo.h
        csvInfo.cpp
        AuxFunctions.cpp
        AuxFunctions.h
)
