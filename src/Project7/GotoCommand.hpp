#pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class GotoCommand : public Command
{
private:


public:
    GotoCommand(string segment = "", string arg1 = "", string arg2 = "")
        : Command(CommandType::Goto, segment, arg1, arg2)
    {

    }

    //label to jump to should be in arg1
    virtual string ToAsm()
    {
        ostringstream result{};
        return result.str();
    }
};