project("sedgewick_wayne_algorithms")
cmake_minimum_required(VERSION 3.9)

# TODO: Set this first flag to your preferred compiler.
# set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)

# Compile to C++17 standard with debug symbols on.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g")

# Set to the most pedantic level, but ignore notes regarding C++98 backward compatibility.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything -Wno-c++98-compat")

# Use libc++ packaged with LLVM-5.0 and built with Homebrew.
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/opt/llvm/include")
# set(CMAKE_EXE_LINKER_FLAGS "-L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib")

# Export the compile commands to JSON for clang-tidy.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Fundamentals
add_executable(lifo-stack-resizing-array src/lifo-stack-resizing-array.cpp)
add_executable(lifo-stack-linked-list src/lifo-stack-linked-list.cpp)
add_executable(fifo-queue src/fifo-queue.cpp)
add_executable(bag-multiset src/bag-multiset.cpp)
add_executable(union-find src/union-find.cpp)

# Sorting
add_executable(selection-sort src/selection-sort.cpp)
add_executable(insertion-sort src/insertion-sort.cpp)
add_executable(shell-sort src/shell-sort.cpp)
