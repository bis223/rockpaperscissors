//
// Created by Bismy Chittattukara Jose on 2022-11-25.
//

#include "include/common/RockPaperScissors.h"
#include "include/common/RockPaperScissorsAIPlayer.h"
#include "include/common/RockPaperScissorsRealPlayer.h"

RPSOptions ValidOptions {{"rock", EMoves::ROCK}, {"paper", EMoves::PAPER}, {"scissors", EMoves::SCISSORS}};
std::vector<std::string> OptionsString {"rock", "paper", "scissors"};

RockPaperScissors::RockPaperScissors(GameType gameType) : mGameType(gameType) {
    mHighScore = -1;
    CreatePlayers();
}

void RockPaperScissors::CalculateScores() {
    const std::optional<int> winnerId = GetWinner();
    if(winnerId) {
        mPlayers[winnerId.value()]->SetScore(mPlayers[winnerId.value()]->GetScore() + 1);
        mHighScore = std::max(mPlayers[winnerId.value()]->GetScore(), mHighScore);
    }
}

std::optional<int> RockPaperScissors::GetWinner() {
    EMoves playerA = mPlayers[0]->GetCurrentMove();
    EMoves playerB = mPlayers[1]->GetCurrentMove();

    if(playerA == EMoves::ROCK) {
        if(playerB == EMoves::PAPER) {
            return 1;
        } else {
            if(playerB == EMoves::ROCK) {
                return std::nullopt;
            }
            return 0;
        }
    }

    if(playerA == EMoves::PAPER) {
        if(playerB == EMoves::SCISSORS) {
            return 1;
        } else {
            if(playerB == EMoves::PAPER) {
                return std::nullopt;
            }
            return 0;
        }
    }

    if(playerA == EMoves::SCISSORS) {
        if(playerB == EMoves::ROCK) {
            return 1;
        } else {
            if(playerB == EMoves::SCISSORS) {
                return std::nullopt;
            }
            return 0;
        }
    }

    assert(false);
    return 0;
}

std::optional<Leaderboard> RockPaperScissors::GetWinnerList() {

    sort(mPlayers.begin(), mPlayers.end(), CompareScore);
    int currentHighScore = mHighScore;
    mLeaderboard.push_back({mHighScore, {}});
    for(size_t i = 0; i < mPlayers.size(); i++) {
        if(mPlayers[i]->GetScore() != currentHighScore) {
            if(i >= mNumberOfRanks) {
               break; // top player list is ready.
            }
            currentHighScore = mPlayers[i]->GetScore();
            mLeaderboard.push_back({currentHighScore, {}});
        }
        mLeaderboard.back().second.push_back(mPlayers[i]->GetUserId());
    }
    mHighScore = 0;
    assert(mLeaderboard.size() > 0);
    if(IsThereAWinner(mLeaderboard)) {
        return mLeaderboard;
    } else {
        return std::nullopt;
    }
}

bool RockPaperScissors::CompareScore(const std::unique_ptr<RockPaperScissorsPlayer>& playerA, const std::unique_ptr<RockPaperScissorsPlayer>& playerB) {
    return playerA->GetScore() > playerB->GetScore();
}

std::string RockPaperScissors::GetInstructions() const {
    return "!! WELCOME TO ROCK PAPER SCISSORS GAME !!\n\n"
           "The winner is determined by the following schema:\n"
          "1. paper beats rock\n"
          "2. rock beats scissors\n"
          "3. scissors beats paper.\n"
           "Take your pick. The game ends after " + std::to_string(mNumberOfRounds) + " rounds."
           " GOOD LUCK..\n";
}

std::string RockPaperScissors::GetHelpText() const {
    return "Pick a word between rock, paper and scissors. Enter the word to submit it.\n";
}

std::vector<PlayerStats> RockPaperScissors::GetStats() const {
    std::vector<PlayerStats> stats;
    for(size_t i = 0; i < mPlayers.size(); i++) {
        stats.push_back({mPlayers[i]->GetUserId(), mPlayers[i]->GetScore(), OptionsString[static_cast<int>(mPlayers[i]->GetCurrentMove())]});
    }
    return stats;
}

bool RockPaperScissors::IsThereAWinner(const Leaderboard& sortedPlayers) const {
    return (sortedPlayers[0].second.size() == mNumberOfRanks);
}

void RockPaperScissors::CreatePlayers() {
    mPlayers.emplace_back(new RockPaperScissorsRealPlayer(0));
    if(mGameType == GameType::PLAYERVSAI) {
        mPlayers.emplace_back(new RockPaperScissorsAIPlayer(1));
    } else {
        mPlayers.emplace_back(new RockPaperScissorsRealPlayer(1));
    }
    assert(mPlayers.size() == mNumberOfPlayers);
}

bool RockPaperScissors::Play(int playerId, std::string input) {
    if(mPlayers[playerId]->IsRealPlayer()) {
        std::transform(input.begin(), input.end(), input.begin(),[](unsigned char c){ return std::tolower(c); });
    }
    return mPlayers[playerId]->PlayTurn(input, ValidOptions);
}

int RockPaperScissors::IsRealPlayer(int playerId) const {
    return mPlayers[playerId]->IsRealPlayer();
}




