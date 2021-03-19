#pragma once
#include "Command.hpp"
#include "StringSplitter.hpp"
#include "AddCommand.hpp"
#include "SubtractCommand.hpp"
#include "NegateCommand.hpp"
#include "EqualCommand.hpp"
#include "GreaterThanCommand.hpp"
#include "LessThanCommand.hpp"
#include "AndCommand.hpp"
#include "OrCommand.hpp"
#include "NotCommand.hpp"

#include "PopCommand.hpp"
#include "PushCommand.hpp"
#include <string>
#include <memory>
#include <vector>
#include <functional>
#include <unordered_map>

using namespace std;
class CommandFactory
{

private:
    unordered_map < string, function<Command* (const string&, const string&, const string&, const string&)>> _commands{};

public:

    CommandFactory()
    {
        _commands["add"] = [](const string& segment, const string& arg1, const string& arg2, const string& file_name) {return new AddCommand(segment, arg1, arg2); };
        _commands["sub"] = [](const string& segment, const string& arg1, const string& arg2, const string& file_name) {return new SubtractCommand(segment, arg1, arg2); };
        _commands["neg"] = [](const string& segment, const string& arg1, const string& arg2, const string& file_name) {return new NegateCommand(segment, arg1, arg2); };
        _commands["eq"] = [](const string& segment, const string& arg1, const string& arg2, const string& file_name) {return new EqualCommand(segment, arg1, arg2); };
        _commands["gt"] = [](const string& segment, const string& arg1, const string& arg2, const string& file_name) {return new GreaterThanCommand(segment, arg1, arg2); };
        _commands["lt"] = [](const string& segment, const string& arg1, const string& arg2, const string& file_name) {return new LessThanCommand(segment, arg1, arg2); };
        _commands["and"] = [](const string& segment, const string& arg1, const string& arg2, const string& file_name) {return new AndCommand(segment, arg1, arg2); };
        _commands["or"] = [](const string& segment, const string& arg1, const string& arg2, const string& file_name) {return new OrCommand(segment, arg1, arg2); };
        _commands["not"] = [](const string& segment, const string& arg1, const string& arg2, const string& file_name) {return new NotCommand(segment, arg1, arg2); };

        _commands["push"] = [](const string& segment, const string& arg1, const string& arg2, const string& file_name) {return new PushCommand(segment, arg1, arg2, file_name); };
        _commands["pop"] = [](const string& segment, const string& arg1, const string& arg2, const string& file_name) {return new PopCommand(segment, arg1, arg2, file_name); };
    }

    Command* fromVector(const vector<string>& text)
    {
        string segment = "";
        string arg1 = "";
        string arg2 = "";
        string file_name = "";

        if (text.size() > 1)
        {
            segment = text[1];
        }
        if (text.size() > 2)
        {
            arg1 = text[2];
        }
        if (text.size() > 3)
        {
            arg2 = text[3];
        }
        if (text.size() > 4)
        {
            file_name = text[4];
        }

        if (_commands.find(text[0]) != _commands.end())
        {
            return _commands[text[0]](segment, arg1, arg2, file_name);
        }
        return nullptr;
    }
};