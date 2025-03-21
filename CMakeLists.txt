cmake_minimum_required(VERSION 3.30)
project(space-game-server)

set(CMAKE_CXX_STANDARD 23)

add_executable(space-game-server
    include/include.h
    include/planet.h
    source/planet.cpp
    main.cpp
)