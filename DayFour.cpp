#include "DayFour.h"

DayFour::DayFour(char* file) :
	AdventDay(file)
{
	std::string s;
	while (std::getline(m_input, s))
	{
		m_map.push_back(s);
	}
}

DayFour::~DayFour()
{

}

int DayFour::findXmas()
{
	int total = 0;
	int n = m_map.size();
	int m = m_map[0].length();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (m_map[i][j] == 'X')
			{
				total += checkString(i, j, n, m);
			}
		}
	}

	return total;
}

int DayFour::findMasX()
{
	int total = 0;
	int n = m_map.size()-1;
	int m = m_map[0].length()-1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (m_map[i][j] == 'A' && checkX(i, j))
			{
				total++;
			}
		}
	}
	return total;
}

int DayFour::checkString(const int& x, const int& y, const int& n, const int& m)
{
	int count = 0;
	int bounds[] = { std::max(0,x - 3), std::min(n-1,x + 3), 
					 std::max(0,y - 3), std::min(m-1,y + 3) };

	for (int k = 0; k < m_dir.size(); k++)
	{
		int idx = 0;
		bool dirValid = true;
		int i = x, j = y;

		while(i >= bounds[0] && i <= bounds[1] &&
			  j >= bounds[2] && j <= bounds[3])
		{
			if (m_map[i][j] != m_match[idx++])
			{
				dirValid = false;
				break;
			}
			i += m_dir[k][0];
			j += m_dir[k][1];
		}

		if (dirValid && idx == 4)
		{
			//printf("(%d, %d) with dir (%d, %d)\n\r", x, y, m_dir[k][0], m_dir[k][1]);
			count++;
		}
	}
	return count;
}

bool DayFour::checkX(const int& x, const int& y)
{
	bool valid = true;
	char topLeft	= m_map[x + 1][y - 1];
	char topRight	= m_map[x + 1][y + 1];
	char botLeft	= m_map[x - 1][y - 1];
	char botRight	= m_map[x - 1][y + 1];
	
	// Corners can't match
	valid &= topLeft != botRight;
	// The values should be valid
	valid &= ((topLeft == 'M' && botRight == 'S') || (topLeft == 'S' && botRight == 'M'));
	// opposide sides should match
	valid &= ((topLeft == topRight || topLeft == botLeft) && (botRight == botLeft || botRight == topRight));

	return valid;
}