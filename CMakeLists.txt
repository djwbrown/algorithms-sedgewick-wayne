project("sedgewick_wayne_algorithms")

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -g")

# Fundamentals
add_executable(lifo-stack-resizing-array src/lifo-stack-resizing-array.cpp)
add_executable(lifo-stack-linked-list src/lifo-stack-linked-list.cpp)
add_executable(fifo-queue src/fifo-queue.cpp)
add_executable(bag-multiset src/bag-multiset.cpp)
add_executable(union-find src/union-find.cpp)

# Sorting
add_executable(selection-sort src/selection-sort.cpp)
