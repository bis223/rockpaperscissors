#pragma once

#include "IUserInterface.h"

class CommandLineInterface : public IUserInterface
{
public:
    CommandLineInterface();

    //IUserInterface
    std::string ReadInput() const override;
    void ShowOutput(const std::string_view& msg) override;
    void ShowQuitOrContinueInstructions() override;
    bool ShouldQuit() const override;

};


