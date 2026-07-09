cmake_minimum_required(VERSION 3.20)

project(L2AuthRecovered LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(L2AuthRecovered
    src/main.cpp
    src/WinMain.cpp
    src/Window.cpp
)

target_include_directories(L2AuthRecovered PRIVATE
    src
    include
)

target_link_libraries(L2AuthRecovered PRIVATE
    user32
    gdi32
)
