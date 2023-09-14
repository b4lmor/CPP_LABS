cmake_minimum_required(VERSION 3.26)
project(LAB0A
	VERSION 1.0.0
	DESCRIPTION "NSU LABS FIT 3 SEMESTER"
	LANGUAGES CXX)

set(PROJECT_SOURCES
        src/main.cpp
		src/module1.cpp
		src/module1.h
		src/module2.cpp
		src/module2.h
		src/module3.cpp
		src/module3.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

