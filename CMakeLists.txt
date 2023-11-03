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

# Create a static library from the source files
add_library(project_lib STATIC ${SOURCES})

# Link each executable to the static library
add_executable(gael ./prog/gael)
target_link_libraries(gael project_lib)

add_executable(test_register tests/test_register.cpp)
target_link_libraries(test_register project_lib)
add_test(register_test ./test_register)

add_executable(test_program tests/test_program.cpp)
target_link_libraries(test_program project_lib)
add_test(program_test ./test_program)

add_executable(test_cpu tests/test_cpu.cpp)
target_link_libraries(test_cpu project_lib)
add_test(cpu_test ./test_cpu)

add_executable(test_bus tests/test_bus.cpp)
target_link_libraries(test_bus project_lib)
add_test(bus_test ./test_bus)

add_executable(test_platform tests/test_platform.cpp)
target_link_libraries(test_platform project_lib)
add_test(platform_test ./test_platform)

add_executable(test_display tests/test_display.cpp)
target_link_libraries(test_display project_lib)
add_test(display_test ./test_display)

add_executable(test_memory tests/test_memory.cpp)
target_link_libraries(test_memory project_lib)
add_test(memory_test ./test_memory)