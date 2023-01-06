//
// Created by Bismy Chittattukara Jose on 2022-11-25.
//

#include "include/common/Game.h"
#include "include/common/RockPaperScissors.h"
#include "include/ui/IUserInterface.h"

Game::Game(IUserInterface &userInterface)
        : mUserInterface(userInterface)
{
}

void Game::Run() {
    bool shouldExit = false;

    GameType gameType = GameType::PLAYERVSAI;

    while (!shouldExit) {
        std::unique_ptr<RockPaperScissors> game = std::make_unique<RockPaperScissors>(gameType);
        mUserInterface.ShowOutput(game->GetInstructions());

        int numberOfRounds = game->GetNumberOfRounds();
        int numberOfPlayers = game->GetNumberOfPlayers();
        int attempts = 0;
        for (int round = 0; round < numberOfRounds; ++round) {
            std::string r = std::to_string(round + 1);
               mUserInterface.ShowOutput("Round " + r + " begins...");
               mUserInterface.ShowOutput("AI made its pick. It is your turn now. Take your pick.");
               for (int player = 0; player < numberOfPlayers; ++player) {

                bool isValidTurn = false;
                while (!isValidTurn) {
                    if(attempts > 0) {
                        mUserInterface.ShowOutput("Invalid choice!!!!!\n");
                        mUserInterface.ShowOutput(game->GetHelpText());
                    }
                    std::string input = "";
                    if(game->IsRealPlayer(player)) {
                        input = mUserInterface.ReadInput();
                    }
                    isValidTurn = game->Play(player, input);
                    attempts++;
                }
                attempts = 0;
            }

            game->CalculateScores();
            mUserInterface.ShowOutput("Scores after round " + r + ":");
            std::vector<PlayerStats> playerStats = game->GetStats();
            for (size_t i = 0; i < playerStats.size(); ++i) {
                std::string prefix = "";
                if(game->IsRealPlayer(i)) {
                    prefix = "You - ";
                } else {
                    prefix = "AI  - ";
                }
                std::string chosenOption = "";

                mUserInterface.ShowOutput(prefix + std::to_string(playerStats[i].playerScore) + " (" + playerStats[i].playerMove + ")");
            }
            mUserInterface.ShowOutput("---------------------------\n");
        }
        mUserInterface.ShowOutput("Game Over\n");
        const auto& winnerList = game->GetWinnerList();
        if(!winnerList) {
            mUserInterface.ShowOutput("It is a tie\n");
        } else {
            for (int i = 0; i < winnerList.value().size(); ++i) {
                const std::vector<int> currentRankPlayers = winnerList.value()[i].second;
                for (int j = 0; j < currentRankPlayers.size(); ++j) {
                    if(game->IsRealPlayer(i)) {
                        mUserInterface.ShowOutput("You win.\n");
                    } else {
                        mUserInterface.ShowOutput("AI win. \n");
                    }
                }
            }
        }
        mUserInterface.ShowOutput("---------------------------\n");
        mUserInterface.ShowQuitOrContinueInstructions();
        if(mUserInterface.ShouldQuit()) {
            shouldExit = true;
        }
    }
}

