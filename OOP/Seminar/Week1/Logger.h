#pragma once
#include "Log.h"
#include <print>

class Logger
{
private:
	Log* logs = nullptr;
	size_t logCount = 0;

	Logger() = default;
public:
	Logger(const Logger& other) = delete;
	Logger(Logger&& other) = delete;

	Logger& operator=(const Logger& other) = delete;
	Logger& operator=(Logger&& other) = delete;

	static Logger& getInstance();

	void addLog(const Log& log);

	void printSortedLogs();

	void printAllOfType(char type);

	void printEarliest();

	void printLatest();

	void printBetween(Time t1, Time t2);
	
	~Logger();
};

