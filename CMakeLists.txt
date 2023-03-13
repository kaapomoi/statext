cmake_minimum_required(VERSION 3.20)

project(statext VERSION 0.0.1
    LANGUAGES CXX C
)

add_subdirectory(lib)
if(ENABLE_EXAMPLES)
    add_subdirectory(examples)
endif()

