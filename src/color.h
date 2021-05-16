#include <ostream>

namespace Color
{
    enum Code
    {
        RED = 31,
        GREEN = 32,
        YELLOW = 33,
        BLUE = 34,
        PURPLE = 35,
        CYAN = 36,
        WHITE = 37,
        DEFAULT = 39,
    };

    std::string toString(Code code)
    {
        std::string str("\e[0;");
        str.append(std::to_string(static_cast<int>(code)));
        str.append("m");
        return str;
    }

    std::ostream &operator<<(std::ostream &os, Code code)
    {
        return os << toString(code);
    }
}

namespace BackgroundColor
{
    enum Code
    {
        RED = 41,
        GREEN = 42,
        YELLOW = 43,
        BLUE = 44,
        PURPLE = 45,
        CYAN = 46,
        WHITE = 47,
        DEFAULT = 49,
    };

    std::string toString(Code code)
    {
        std::string str("\e[");
        str.append(std::to_string(static_cast<int>(code)));
        str.append("m");
        return str;
    }

    std::ostream &operator<<(std::ostream &os, Code code)
    {
        return os << toString(code);
    }
}
