#pragma once
#include "AdventDay.h"
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

class DayOne : AdventDay {
public:
	DayOne(char* file);
	~DayOne();

	int GetDiff();
	long GetSimilar();
private:
	std::vector<int> m_left;
	std::vector<int> m_right;
	std::map<int, int> m_occur;
};