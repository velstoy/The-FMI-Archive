#include "Logger.h"

Logger& Logger::getInstance()
{
	static Logger logger;
	return logger;
}

Logger::~Logger()
{
	delete[] logs;
	logs = nullptr;
}

void Logger::addLog(const Log& log)
{
	Log* extendedLogs = new Log[logCount + 1];

	for (size_t i = 0; i < logCount; i++)
	{
		extendedLogs[i] = logs[i];
	}

	extendedLogs[logCount] = log;

	logCount++;

	delete[] logs;

	logs = extendedLogs;
}

void Logger::printSortedLogs()
{
	Log* logs = new Log[logCount];

	for (size_t i = 0; i < logCount; i++)
	{
		logs[i] = this->logs[i];
	}

	for (size_t i = 0; i < logCount; i++)
	{
		unsigned int minIndex = i;
		for (size_t j = i + 1; j < logCount; j++)
		{
			if (logs[minIndex].getTimeElapsed() > logs[j].getTimeElapsed())
			{
				minIndex = j;
			}
		}

		Log temp = logs[i];
		logs[i] = logs[minIndex];
		logs[minIndex] = temp;

		logs[i].printSelf();
	}
}

void Logger::printAllOfType(char type)
{
	for (size_t i = 0; i < logCount; i++)
	{
		if (logs[i].getType() == type)
		{
			logs[i].printSelf();
		}
	}
}

void Logger::printEarliest()
{
	logs[0].printSelf();
}

void Logger::printLatest()
{
	logs[logCount - 1].printSelf();
}

void Logger::printBetween(Time t1, Time t2)
{
	for (size_t i = 0; i < logCount; i++)
	{
		if (logs[i].getTimeElapsed() > t1.getTimeInSeconds() && logs[i].getTimeElapsed() < t2.getTimeInSeconds()) 
		{
			logs[i].printSelf();
		}
	}
}
