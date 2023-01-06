//
// Created by Bismy Chittattukara Jose on 2022-11-26.
//

#pragma once

#include <unordered_map>
#include <string>

enum class GameType { PLAYERVSAI};

enum class EMoves { ROCK = 0, PAPER = 1, SCISSORS };
typedef std::unordered_map<std::string, EMoves> RPSOptions;

typedef std::vector<std::pair<int, std::vector<int>>> Leaderboard;

struct PlayerStats {
    int playerId = 0;
    int playerScore = 0;
    std::string playerMove = "";
};