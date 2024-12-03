#pragma once
#include "AdventDay.h"
#include <vector>
#include <string>
#include <regex>

class DayThree :
    public AdventDay
{
public:
    DayThree(char* file);

    long long preformMult(const bool& constFlow);
private:
    std::vector<std::string> m_opts;
    const std::regex m_mulRegex = std::regex(R"((mul\([0-9]{1,3}\,[0-9]{1,3}\)|do(n't)?\(\)))");

    void extractInts(const std::string& input, int val[]);
};

