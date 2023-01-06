//
// Created by Bismy Chittattukara Jose on 2022-11-26.
//

#include "include/common/RockPaperScissorsRealPlayer.h"

RockPaperScissorsRealPlayer::RockPaperScissorsRealPlayer(int userId) : mUserId(userId) {}

bool RockPaperScissorsRealPlayer::PlayTurn(const std::string& input, const std::unordered_map<std::string, EMoves>& validOptions) {
    const auto& it = validOptions.find(input);
    if(it != validOptions.end()) {
        mActiveMove = it->second;
        return true;
    }
    return false;
}

int RockPaperScissorsRealPlayer::GetUserId() {
    return mUserId;
}

EMoves RockPaperScissorsRealPlayer::GetCurrentMove() {
    return mActiveMove;
}

bool RockPaperScissorsRealPlayer::IsRealPlayer() {
    return true;
}
