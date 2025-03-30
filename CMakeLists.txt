cmake_minimum_required(VERSION 3.28)
project(space-game-server)

set(CMAKE_CXX_STANDARD 23)

add_executable(space-game-server
    main.cpp
    include/include.h
        include/space-objects.h
        source/space-objects.cpp
)
