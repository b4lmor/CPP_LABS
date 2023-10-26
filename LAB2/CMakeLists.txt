cmake_minimum_required(VERSION 3.26)
project(LAB2
	VERSION 1.0.0
	DESCRIPTION "NSU LABS FIT 3 SEMESTER"
	LANGUAGES CXX)

add_subdirectory(googletest)

set(PROJECT_SOURCES
        src/main.cpp
		src/utils/GameArgs.h
		src/utils/enum/GameMode.h
		src/game/AGame.h
		src/prisoner/Prisoner.h
		src/strategy/AStrategy.h
		src/utils/enum/Choice.h
        src/matrix/GameMatrix.h
		src/game/GameFactory.h
        src/utils/file_utils/file_basic.h
		src/utils/file_utils/file_basic.cpp
		src/matrix/GameMatrix.cpp
		src/utils/enum/Choice.cpp
		src/utils/regex_utils.h
		src/utils/regex_utils.cpp
		src/strategy/impl/AltruistStrategy.cpp
		src/strategy/impl/AltruistStrategy.h
		src/strategy/impl/BetrayerStrategy.h
		src/strategy/impl/BetrayerStrategy.cpp
		src/strategy/StrategyFactory.cpp
		src/strategy/StrategyFactory.h
		src/prisoner/Prisoner.cpp
		src/utils/my_types/MyTypes.h
		src/game/impl/DetailedGame.cpp
		src/game/impl/DetailedGame.h
		src/strategy/impl/RandomStrategy.cpp
		src/strategy/impl/RandomStrategy.h
		src/utils/GameArgs.cpp
		src/utils/enum/GameMode.cpp
		src/game/GameFactory.cpp
		src/game/impl/FastGame.cpp
		src/game/impl/FastGame.h
		src/utils/combinations_utils.cpp
		src/utils/combinations_utils.h
		src/game/impl/TournamentGame.cpp
		src/game/impl/TournamentGame.h
		src/strategy/impl/BonafideStrategy.cpp
		src/strategy/impl/BonafideStrategy.h
		src/strategy/impl/MimickerStrategy.cpp
		src/strategy/impl/MimickerStrategy.h
		src/strategy/impl/CombinedStrategy.cpp
		src/strategy/impl/CombinedStrategy.h
		src/renderer/GameRenderer.cpp
		src/renderer/GameRenderer.h
		test/strategytest/StrategyTest.cpp
		test/matrixtest/MatrixTest.cpp
		test/gametest/GameTest.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} gtest gtest_main)
