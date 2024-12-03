#include "DayOne.h"

// We are given a 2D array in a file
// We need to find the difference between the lowest values of both sides of the array
// arr[i][0] is the i-th element of the first array
// arr[i][1] is the i-th element of the second array

DayOne::DayOne(char* file) :
	AdventDay(file)
{
	// Read in the array
	int first, second;
	while (m_input >> first >> second)
	{
		m_left.push_back(first);
		m_right.push_back(second);
	}
}

DayOne::~DayOne()
{

}

int DayOne::GetDiff()
{
	int sumOfDiff = 0;
	size_t n = m_left.size();

	// Sort the arrays
	std::sort(m_left.begin(), m_left.end());
	std::sort(m_right.begin(), m_right.end());

	// get the diff of each one
	for (int i = 0; i < n; i++)
	{
		sumOfDiff += std::abs(m_left[i] - m_right[i]);
	}

	return sumOfDiff;
}

long DayOne::GetSimilar()
{
	// The arrays are already sorted
	long sumOfSim = 0;
	size_t n = m_left.size();

	// Create a map of the values in the right
	for (int i : m_right)
	{
		m_occur[i]++;
	}

	// For each value check if its in the right list
	for (int i : m_left)
	{
		// Multiply the count by the index
		sumOfSim += m_occur[i] * i;
	}

	return sumOfSim;
}