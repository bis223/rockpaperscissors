//
// Created by Bismy Chittattukara Jose on 2022-11-26.
//

#pragma once

#include "Defs.h"

class RockPaperScissorsPlayer {
public:
    virtual ~RockPaperScissorsPlayer() = default;

    virtual bool PlayTurn(const std::string& input, const std::unordered_map<std::string, EMoves>& validOptions) = 0;
    virtual bool IsRealPlayer() = 0;
    virtual EMoves GetCurrentMove() = 0;
    virtual int GetUserId() = 0;

    void SetScore(int score);
    int GetScore();

private:
    int mScore = 0;
};