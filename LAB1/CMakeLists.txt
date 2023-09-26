cmake_minimum_required(VERSION 3.26)
project(LAB1
	VERSION 1.0.0
	DESCRIPTION "NSU LABS FIT 3 SEMESTER"
	LANGUAGES CXX)

add_subdirectory(googletest)

set(PROJECT_SOURCES
        src/BitArray.h
		src/BitArray.cpp
		test/test.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

