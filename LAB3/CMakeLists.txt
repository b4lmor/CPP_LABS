cmake_minimum_required(VERSION 3.26)
project(LAB3
	VERSION 1.0.0
	DESCRIPTION "NSU LABS FIT 3 SEMESTER"
	LANGUAGES CXX)

set(PROJECT_SOURCES
        src/main.cpp
		src/utils/ParsedArgs.cpp
		src/utils/ParsedArgs.h
		src/exception/MyException.h
		src/exception/BadInputException.h
		src/types/Mode.h
		src/utils/Helper.h
		src/soundprocessor/SoundProcessor.cpp
		src/soundprocessor/SoundProcessor.h
		src/soundprocessor/task/Task.h
		src/exception/IOException.h
		src/soundprocessor/task/impl/MuteTask.cpp
		src/soundprocessor/task/impl/MuteTask.h
		src/configreader/ConfigReader.cpp
		src/configreader/ConfigReader.h
		src/utils/StringUtils.cpp
		src/utils/StringUtils.h
		src/soundprocessor/task/TaskType.h
		src/soundprocessor/task/impl/MixTask.cpp
		src/soundprocessor/task/impl/MixTask.h
		src/soundprocessor/wav/WavUtils.h
		src/soundprocessor/wav/WavUtils.h
		src/soundprocessor/task/impl/CompressTask.cpp
        src/soundprocessor/task/impl/CompressTask.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

