//
// Created by Bismy Chittattukara Jose on 2022-11-26.
//

#pragma once

#include "RockPaperScissorsPlayer.h"

class RockPaperScissorsAIPlayer : public RockPaperScissorsPlayer {
public:
    explicit RockPaperScissorsAIPlayer(int userId);

    bool PlayTurn(const std::string& input, const std::unordered_map<std::string, EMoves>& validOptions) override;
    bool IsRealPlayer() override;
    int GetUserId() override;
    EMoves GetCurrentMove() override;

private:
    bool IsValidOption(int option) const;
    EMoves mActiveMove;
    int mUserId = 0;
};
