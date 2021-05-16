#include <cstdio>
#include <iostream>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>
#include <regex>
#include <iomanip>
using namespace std;

string exec(const char *cmd);
string unquote(string input);

string join(char delimiter, vector<string> data);
vector<string> split(char delimiter, string input);
