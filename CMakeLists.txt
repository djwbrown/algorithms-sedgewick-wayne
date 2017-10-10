project("sedgewick_wayne_algorithms")

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -g")

add_executable(lifo-stack-resizing-array src/lifo-stack-resizing-array.cpp)
add_executable(lifo-stack-linked-list src/lifo-stack-linked-list.cpp)
