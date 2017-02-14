project("sedgewick_wayne_algorithms")

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -g")

add_executable(lifo-stack-resizing-array src/lifo-stack-resizing-array.cpp)
