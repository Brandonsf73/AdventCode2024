#include "DayTwo.h"
#include <string>
#include <sstream>

DayTwo::DayTwo(char* file) :
	AdventDay(file)
{
	// Read in the line
	std::string line;
	while (std::getline(m_input, line))
	{
		std::istringstream streamLine(line);
		std::string token;
		std::vector<int> report;
		while (std::getline(streamLine, token, ' '))
		{
			report.push_back(std::stoi(token));
		}
		m_reports.push_back(report);
	}
	m_safeReports = std::vector<int>(m_reports.size(), -1);
}

DayTwo::~DayTwo()
{

}

bool DayTwo::CheckReport(const std::vector<int>& report, int& badIdx)
{
	bool safe = true;
	int n = report.size();
	int total = 0;
	for (int i = 0; i < n - 1; i++)
	{
		// get the difference of the values
		int diff = report[i] - report[i + 1];

		// Check that its within the threshold
		if ((diff > -1 || diff < -3) &&
			(diff < 1 || diff > 3))
		{
			safe = false;
			badIdx = i;
			break;
		}
		// Check that its not against the grain
		if ((total < 0 && diff > 0) ||
			(total > 0 && diff < 0))
		{
			safe = false;
			badIdx = i;
			break;
		}
		total += diff;
	}
	return safe;
}

int DayTwo::checkSafe()
{
	int totalSafe = 0;
	int n = m_reports.size();

	// Check that each report ascends or desencds only
	for (int i = 0; i < n; i++)
	{
		int badIdx = -1;
		totalSafe += CheckReport(m_reports[i], badIdx) ? 1 : 0;
		m_safeReports[i] = badIdx;
	}

	return totalSafe;
}

int DayTwo::checkSafeDamp()
{
	int totalSafe = 0;
	int n = m_reports.size();

	// Check that each report ascends or desencds only
	for (int i = 0; i < n; i++)
	{
		if (m_safeReports[i] != -1)
		{
			// Remove the bad index
			m_reports[i].erase(m_reports[i].begin() + m_safeReports[i]);
			// Check the report again
			totalSafe += CheckReport(m_reports[i], m_safeReports[i]) ? 1 : 0;
		}
		else
		{
			totalSafe++;
		}
	}

	return totalSafe;
}