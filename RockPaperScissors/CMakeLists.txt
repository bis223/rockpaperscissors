cmake_minimum_required(VERSION 3.20)
project(RockPaperScissors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(RockPaperScissors
        source/common/main.cpp
        source/common/ui/CommandLineInterface.cpp
        include/ui/CommandLineInterface.h
        include/ui/IUserInterface.h
        source/common/Game.cpp
        include/common/Game.h
        source/common/RockPaperScissors.cpp
        include/common/RockPaperScissors.h
        source/common/RockPaperScissorsPlayer.cpp
        include/common/RockPaperScissorsPlayer.h
        source/common/RockPaperScissorsAIPlayer.cpp
        include/common/RockPaperScissorsAIPlayer.h
        source/common/RockPaperScissorsRealPlayer.cpp
        include/common/RockPaperScissorsRealPlayer.h
        include/common/Defs.h)
