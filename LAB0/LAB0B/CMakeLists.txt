cmake_minimum_required(VERSION 3.26)
project(LAB0B
	VERSION 1.0.0
	DESCRIPTION "NSU LABS FIT 3 SEMESTER"
	LANGUAGES CXX)

set(PROJECT_HEADERS
		src/utils.h
		src/my_exception.h
)

set(PROJECT_SOURCES
		src/main.cpp
		src/utils.cpp
		src/my_exception.cpp
		src/file_utils.h
		src/file_utils.cpp
		src/word_counter.h
		src/word_counter.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})

