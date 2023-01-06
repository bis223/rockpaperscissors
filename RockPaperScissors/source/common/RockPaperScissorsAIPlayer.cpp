//
// Created by Bismy Chittattukara Jose on 2022-11-26.
//

#include "include/common/RockPaperScissorsAIPlayer.h"
#include <random>

RockPaperScissorsAIPlayer::RockPaperScissorsAIPlayer(int userId) : mUserId(userId) {}

bool RockPaperScissorsAIPlayer::PlayTurn(const std::string& input, const std::unordered_map<std::string, EMoves>& validOptions) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,validOptions.size() - 1);
    int aiMove = dist(rng);
    assert(IsValidOption(aiMove));
    mActiveMove = static_cast<EMoves>(aiMove);
    return true;
}

EMoves RockPaperScissorsAIPlayer::GetCurrentMove() {
    return mActiveMove;
}

bool RockPaperScissorsAIPlayer::IsRealPlayer() {
    return false;
}

int RockPaperScissorsAIPlayer::GetUserId() {
    return mUserId;
}

bool RockPaperScissorsAIPlayer::IsValidOption(int option) const {
    EMoves move = static_cast<EMoves>(option);

    switch (move) {
        case EMoves::ROCK:
        case EMoves::PAPER:
        case EMoves::SCISSORS:
            return true;
        default:
            return false;
    }

}

