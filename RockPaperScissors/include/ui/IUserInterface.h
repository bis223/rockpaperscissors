#pragma once
#include <string>

class IUserInterface
{
public:
    virtual ~IUserInterface() = default;

    virtual std::string ReadInput() const = 0;
    virtual void ShowOutput(const std::string_view& msg) = 0;
    virtual void ShowQuitOrContinueInstructions() = 0;
    virtual bool ShouldQuit() const = 0;
};


