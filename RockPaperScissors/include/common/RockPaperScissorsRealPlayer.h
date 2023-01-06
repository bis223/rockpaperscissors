//
// Created by Bismy Chittattukara Jose on 2022-11-26.
//

#pragma once

#include "RockPaperScissorsPlayer.h"

class RockPaperScissorsRealPlayer : public RockPaperScissorsPlayer {
public:
    explicit RockPaperScissorsRealPlayer(int userId);

    bool PlayTurn(const std::string& input, const std::unordered_map<std::string, EMoves>& validOptions) override;
    bool IsRealPlayer() override;
    int GetUserId() override;
    EMoves GetCurrentMove() override;

private:
    EMoves mActiveMove;
    int mUserId = 0;
};

