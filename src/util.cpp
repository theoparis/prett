#include "./util.h"

string exec(const char *cmd)
{
    std::array<char, 128> buffer;
    string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe)
        throw std::runtime_error("popen() failed!");
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
        result += buffer.data();
    return result;
}

string unquote(string input)
{
    input.erase(std::remove(input.begin(), input.end(), '\"'), input.end());
    return input;
}

/*! note: input is assumed to not contain NUL characters
 */
vector<string> split(char delimiter, string input)
{
    using namespace std;
    vector<string> output;
    for (auto cur = begin(input), beg = cur;; ++cur)
    {
        if (cur == end(input) || *cur == delimiter || !*cur)
        {
            output.insert(output.end(), string(beg, cur));
            if (cur == end(input) || !*cur)
                break;
            else
                beg = next(cur);
        }
    }
    return output;
}
