#include "AdventDay.h"
#include <vector>

class DayTwo : AdventDay
{
public:
	DayTwo(char* file);
	~DayTwo();

	int checkSafe();
	int checkSafeDamp();
private:
	std::vector<std::vector<int>> m_reports;
	std::vector<int> m_safeReports;

	bool CheckReport(const std::vector<int>& report, int& badIdx);
};