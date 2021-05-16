#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <ghc/filesystem.hpp>
#include <fmt/core.h>
#include <fmt/core.h>
#include "./color.h"
#include "./util.h"

using namespace std;

namespace fs = ghc::filesystem;

int main(int argc, char *argv[])
{
    string directoryPrefix("");
    string filePrefix("");
    string errPrefix("");
    string successPrefix("");
    string subCommand(argv[1]);
    transform(subCommand.begin(), subCommand.end(), subCommand.begin(), ::tolower);
    vector<string> args(argv + 2, argv + argc);

    vector<string> tmp;
    for (int i = 0; i < args.size(); i++)
    {
        if (args.at(i) != " ")
            tmp.push_back(args.at(i));
    }
    args = tmp;

    if (subCommand == "ls")
    {
        string cmd("sh -c \"ls --group-directories-first -1 ");
        for (size_t i = 0; i < args.size(); i++)
        {
            cmd.append(args[i]);
            if (i < args.size() - 1)
                cmd.append(" ");
        }
        cmd.append("\"");
        // For debug purposes:
        // cout << "Running: " << cmd << endl;
        string lsResult = exec(cmd.c_str());

        vector<string> files = split('\n', lsResult);
        for (size_t i = 0; i < files.size(); i++)
        {
            string fileName = unquote(files[i]);
            if (fileName != "" && fileName != " ")
            {
                bool isDirectory = fs::exists(fileName) ? fs::is_directory(fileName) : false;
                fmt::print("{}{}{} {}\n", isDirectory ? Color::toString(Color::PURPLE) : Color::toString(Color::BLUE), isDirectory ? directoryPrefix : filePrefix, Color::toString(Color::WHITE), fileName);
            }
        }
    }

    return 0;
}
