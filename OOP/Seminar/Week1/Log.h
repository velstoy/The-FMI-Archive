#pragma once
#include "Time.h"
class Log
{
	Time time;
	char type = 'I';
	char* message = nullptr;

	void copyFrom(const Log& other);

public:
	Log() = default;
	Log(const unsigned hours, const unsigned minutes, const unsigned seconds, const char type, const char* message);

	Log(const Log& other);
	Log& operator=(const Log& other);

	unsigned getTimeElapsed() const;

	char getType() const;

	void printSelf() const;

	friend Log getFormattedLogInput();

	~Log();
};

Log getFormattedLogInput();