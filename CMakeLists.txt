cmake_minimum_required(VERSION 3.12)
project(Project)

set(CMAKE_CXX_STANDARD 11)
add_executable(Project tracelib.h tracelib.cpp test.cpp eventEntries.h)
