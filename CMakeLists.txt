cmake_minimum_required(VERSION 2.8)

project(3A-SEI-SoC-POO-Project)
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)
include_directories(./include)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wconversion -std=gnu99")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wconversion -std=gnu++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -std=gnu++11")

file(GLOB SOURCES "src/*.cpp")

include(CTest)
enable_testing()

# add_executable(hello            ./01-hello/hello.cpp)
add_executable(gael ./prog/gael ${SOURCES}) 
add_executable(test_bon tests/test_bon.cpp ${SOURCES})
add_executable(test_register tests/test_register.cpp ${SOURCES})
add_executable(test_program tests/test_program.cpp ${SOURCES})
add_executable(test_cpu tests/test_cpu.cpp ${SOURCES})

add_test(tjrs_bon ./test_bon)
add_test(register_test ./test_register)
add_test(program_test ./test_program)
add_test(cpu_test ./test_cpu)
