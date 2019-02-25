cmake_minimum_required(VERSION 3.2)
project(Complex2574 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(vector_test Vector.hpp student_tests1.cpp)
add_executable(sieve_test Sieve.cpp Sieve.hpp Vector.hpp student_tests.cpp)

enable_testing()

add_test(v_test vector_test)
