cmake_minimum_required(VERSION 3.25)
project(Project3 C)

set(CMAKE_C_STANDARD 11)

add_executable(Project3
        project3_rental.c project3_escalator.c review.c)
