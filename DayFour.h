#pragma once
#include "AdventDay.h"
#include <vector>
#include <string>

class DayFour :
    public AdventDay
{
public:
    DayFour(char* file);
    ~DayFour();

    int findXmas();
    int findMasX();
private:
    std::vector<std::string> m_map;
    const char* m_match = "XMAS";
    const std::vector<std::vector<int>> m_dir = { {0,1}, {0,-1}, {1,0}, {1,1}, {1,-1}, {-1,0}, {-1,1}, {-1,-1} };

    int checkString(const int& x, const int& y, const int& n, const int& m);
    bool checkX(const int& x, const int& y);
};

