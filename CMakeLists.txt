cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -g")

project("vscode-testing")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(main 
  src/main.cpp
  src/shared/lib/Game.cpp
)

target_include_directories(main PRIVATE
  src
  src/shared/lib
)

target_link_libraries(main ${CURSES_LIBRARIES})