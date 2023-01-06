#include "include/ui/CommandLineInterface.h"

#include <iostream>

namespace {
void ClearScreen() {
    for (int i = 0; i < 80; ++i) {
        std::cout << std::endl;
    }
}
}
CommandLineInterface::CommandLineInterface() {
    ClearScreen();
}

std::string CommandLineInterface::ReadInput() const {
    std::string input;
    std::getline(std::cin, input);
    std::cout << std::endl;
    return input;
}

void CommandLineInterface::ShowOutput(const std::string_view& msg) {
    std::cout << msg << std::endl;
}

void CommandLineInterface::ShowQuitOrContinueInstructions() {
    std::cout << "Enter any key to quit or press return to start a new game." << std::endl;
}

bool CommandLineInterface::ShouldQuit() const{
    std::string input;
    std::getline(std::cin, input);
    return input.size() != 0;
}
