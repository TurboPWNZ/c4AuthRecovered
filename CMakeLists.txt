cmake_minimum_required(VERSION 3.20)

project(L2AuthRecovered LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(L2AuthRecovered WIN32
    src/main.cpp
    src/WinMain.cpp
    src/Window.cpp
 "src/Application/Application.h" "src/Application/Application.cpp" "src/Crypto/Crypto.cpp" "src/Crypto/Crypto.h" "src/Exception/Exception.h" "src/Exception/Exception.cpp" "src/Network/Network.h" "src/Network/Network.cpp")

target_compile_definitions(L2AuthRecovered PRIVATE
    UNICODE
    _UNICODE
)

target_include_directories(L2AuthRecovered PRIVATE
    src
    include
)

target_link_libraries(L2AuthRecovered PRIVATE
    user32
    gdi32
)
