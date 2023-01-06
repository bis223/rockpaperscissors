//
// Created by Bismy Chittattukara Jose on 2022-11-25.
//

#pragma once

#include "include/common/RockPaperScissorsPlayer.h"

#include <vector>
#include <string>
#include <optional>
#include <memory>
#include <unordered_map>
#include "Defs.h"

class RockPaperScissors {
public:
    explicit RockPaperScissors(GameType gameType);

    bool Play(int playerId, std::string input);
    void CalculateScores();
    std::vector<PlayerStats> GetStats() const;
    std::optional<Leaderboard> GetWinnerList();

    int GetNumberOfRounds() { return mNumberOfRounds; }
    int GetNumberOfPlayers() { return mNumberOfPlayers; }
    int IsRealPlayer(int playerId) const;

    std::string GetInstructions() const;
    std::string GetHelpText() const;

private:

    void CreatePlayers();
    std::optional<int> GetWinner();
    bool IsThereAWinner(const Leaderboard& sortedPlayers) const;

    static bool CompareScore(const std::unique_ptr<RockPaperScissorsPlayer>& playerA, const std::unique_ptr<RockPaperScissorsPlayer>& playerB);
    std::vector<std::unique_ptr<RockPaperScissorsPlayer>> mPlayers;
    Leaderboard mLeaderboard;
    GameType mGameType = GameType::PLAYERVSAI;
    int mNumberOfRounds = 3;
    const int mNumberOfPlayers = 2;
    int mNumberOfRanks = 1;
    int mHighScore = 0;

};
