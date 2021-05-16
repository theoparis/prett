#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <ghc/filesystem.hpp>
#include <fmt/core.h>
#include <fmt/core.h>
#include <regex>
#include "ccore.h"

using namespace std;

namespace fs = ghc::filesystem;

string directoryPrefix("");
string filePrefix("");
string errPrefix("");
string successPrefix("");
regex fileRegex("\\..*", regex_constants::icase);
regex configDirRegex("config$", regex_constants::icase);
regex dataDirRegex("data$", regex_constants::icase);
regex nodeModulesRegex("node_modules$", regex_constants::icase);
regex npmRegex("package.json$", regex_constants::icase);
regex dockerRegex("docker-compose.yml|Dockerfile$", regex_constants::icase);
regex gitRegex(".gitignore|.git$", regex_constants::icase);
regex cssRegex(".css$", regex_constants::icase);
regex sassRegex(".scss|sass$", regex_constants::icase);
regex githubRegex(".github$", regex_constants::icase);
regex readmeRegex("readme.md|rst", regex_constants::icase);
regex musicRegex(".mp3|wav|ogg", regex_constants::icase);
regex videoRegex(".mov|mp4|flv|mkv", regex_constants::icase);
regex discRegex(".iso|img", regex_constants::icase);
regex imageRegex(".jpe?g|png|gif", regex_constants::icase);
regex compressedRegex(".zip|tar|tar.gz|7z|rar", regex_constants::icase);

string getIcon(string fileName)
{

    if (fileName.ends_with(".cpp"))
        return Color::toString(Color::BLUE) + "";
    else if (fileName.ends_with(".ts"))
        return Color::toString(Color::BLUE) + "";
    else if (fileName.ends_with(".js"))
        return Color::toString(Color::YELLOW) + "";
    else if (fileName.ends_with(".json") || fileName.ends_with(".json5") || fileName.ends_with(".jsonc"))
        return Color::toString(Color::YELLOW) + "";
    else if (regex_search(fileName, configDirRegex))
        return Color::toString(Color::CYAN) + "";
    else if (regex_search(fileName, dataDirRegex))
        return Color::toString(Color::CYAN) + "";
    else if (regex_search(fileName, nodeModulesRegex))
        return Color::toString(Color::RED) + "";
    else if (regex_search(fileName, npmRegex))
        return Color::toString(Color::RED) + "";
    else if (regex_search(fileName, dockerRegex))
        return Color::toString(Color::CYAN) + "";
    else if (regex_search(fileName, gitRegex))
        return Color::toString(Color::PURPLE) + "";
    else if (regex_search(fileName, cssRegex))
        return Color::toString(Color::BLUE) + "";
    else if (regex_search(fileName, sassRegex))
        return Color::toString(Color::RED) + "";
    else if (regex_search(fileName, githubRegex))
        return Color::toString(Color::WHITE) + "";
    else if (regex_search(fileName, readmeRegex))
        return Color::toString(Color::CYAN) + "";
    else if (regex_search(fileName, musicRegex))
        return Color::toString(Color::PURPLE) + "";
    else if (regex_search(fileName, videoRegex))
        return Color::toString(Color::BLUE) + "";
    else if (regex_search(fileName, discRegex))
        return Color::toString(Color::GREEN) + "";
    else if (regex_search(fileName, imageRegex))
        return Color::toString(Color::RED) + "";
    else if (regex_search(fileName, compressedRegex))
        return Color::toString(Color::YELLOW) + "";
    else
    {
        bool isDirectory = !regex_search(fileName, fileRegex);
        return isDirectory ? Color::toString(Color::PURPLE) + directoryPrefix : Color::toString(Color::BLUE) + filePrefix;
    }
}

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        cout << "Usage: " << Color::toString(Color::PURPLE) << "prett"
             << Color::toString(Color::DEFAULT) << " <subcommand> [options]" << endl;
        cout << "   " << Color::toString(Color::CYAN) << "ls"
             << Color::toString(Color::DEFAULT) << ": List files in a directory." << endl;
        return 0;
    }

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
        string cmd("sh -c \"ls -1 ");
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

                fmt::print("{}{} {}\n", getIcon(fileName), Color::toString(Color::DEFAULT), fileName);
            }
        }
    }

    return 0;
}
