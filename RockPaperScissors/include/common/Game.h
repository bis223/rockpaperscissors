//
// Created by Bismy Chittattukara Jose on 2022-11-25.
//

#pragma once

class IUserInterface;

class Game {
public:
    explicit Game(IUserInterface& userInterface);
    void Run();

private:
    IUserInterface& mUserInterface;
};
