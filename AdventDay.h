#pragma once
#include <fstream>
#include <iostream>

// Base class for each day, everyday has to read from a file
// Make sure that all of the files it reads are closed
class AdventDay 
{
public:
	std::ifstream m_input;

	AdventDay(char* file)
	{
		m_input = std::ifstream(file);
	}
	virtual ~AdventDay()
	{
		if (m_input.is_open())
		{
			m_input.close();
		}
	}
};