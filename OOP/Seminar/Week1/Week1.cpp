#include <iostream>
#include "Logger.h"
#include "Log.h"

int main()
{
	int count = 0;
	std::cin >> count;

	std::cin.ignore();

	for (size_t i = 0; i < count; i++)
	{
		Log log = getFormattedLogInput();
		Logger::getInstance().addLog(log);
	}

	Logger::getInstance().printSortedLogs();

	return 0;
}