#include <stdio.h>
#include <iostream>
#include <string>
#include "DayHeaders.h"

int main(int argc, char* argv[])
{
	// we should only have two inputs, the day, and the test file
  	if (argc != 3)
	{
		return -1;
	}

	int day = std::atoi(argv[1]);
	std::cout << "Solving Day " << day << std::endl;
	if (day == 1)
	{
		DayOne one(argv[2]);

		int sumOfDiff = one.GetDiff();
		std::cout << "Sum of all the differences: " << sumOfDiff << std::endl;

		long sumOfSim = one.GetSimilar();
		std::cout << "Sum of all the Similarity: " << sumOfSim << std::endl;
	}
	else if (day == 2)
	{
		DayTwo two(argv[2]);

		int safeReports = two.checkSafe();
		std::cout << "Total Safe Reports without Dampener: " << safeReports << std::endl;

		int safeReportsDamp = two.checkSafeDamp();
		std::cout << "Total Safe Reports WITH Dampener: " << safeReportsDamp << std::endl;
	}
	else if (day == 3)
	{
		DayThree three(argv[2]);

		long long multTotal = three.preformMult(false);
		std::cout << "Multiplication Total without Flow: " << multTotal << std::endl;

		long long multTotalFlow = three.preformMult(true);
		std::cout << "Mutiplication total with Flow: " << multTotalFlow << std::endl;
	}

	return 0;
}