#pragma once
#include "Command.hpp"
#include "PopCommand.hpp"
#include "PushCommand.hpp"

class OrCommand : public Command
{
public:
    OrCommand(string segment = "", string arg1 = "", string arg2 = "")
        : Command(CommandType::Or, segment, arg1, arg2)
    {

    }

    virtual string ToAsm()
    {
        ostringstream result{};

        return result.str();
    }
};