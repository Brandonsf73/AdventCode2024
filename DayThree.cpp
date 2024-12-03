#include "DayThree.h"

DayThree::DayThree(char* file) :
	AdventDay(file)
{
	std::string s;
	std::regex_token_iterator<std::string::iterator> rend;
	

	// Parse the input till we find all of the mult operations, save them for processing
	while (std::getline(m_input, s))
	{
		std::regex_token_iterator<std::string::iterator> matches(s.begin(), s.end(), m_mulRegex);
		while (matches != rend)
		{
			m_opts.push_back(*matches);
			matches++;
		}
	}
	
}

long long DayThree::preformMult(const bool& condFlow)
{
	long long total = 0;
	bool doMult = true;
	for (std::string s : m_opts)
	{
		if (doMult && s[0] == 'm')
		{
			int val[] = { 0,0 };
			extractInts(s, val);
			total += val[0] * val[1];
		}
		else if (condFlow && s[0] == 'd')
		{
			doMult = (s == "do()");
		}
	}
	return total;
}

void DayThree::extractInts(const std::string& input, int val[])
{
	// first value
	int start = 0;
	for (int i = 0; i < 2; i++)
	{
		while (input[start] > '9' || input[start] < '0')
		{
			start++;
		}
		int end = start;
		while (input[end] <= '9' && input[end] >= '0')
		{
			end++;
		}
		int place = 1;
		int temp = end;
		while (end > start)
		{
			end--;
			val[i] += (input[end] - '0') * place;
			place *= 10;
		}
		start = temp;
	}
}