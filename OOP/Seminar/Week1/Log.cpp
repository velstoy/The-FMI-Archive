#define _CRT_SECURE_NO_WARNINGS

#include "Log.h"
#include <cstring>
#include <print>
#include <iostream>

void Log::copyFrom(const Log& other)
{
	time = other.time;
	type = other.type;

	delete[] message;
	message = new char[strlen(other.message) + 1];
	strcpy(message, other.message);
}

Log::Log(const unsigned hours, const unsigned minutes, const unsigned seconds, const char type, const char* message)
	: time(hours, minutes, seconds), type(type)
{
	this->message = new char[std::strlen(message) + 1];
	std::strcpy(this->message, message);
}

Log::Log(const Log& other)
{
	copyFrom(other);
}

Log& Log::operator=(const Log& other)
{
	if (this != &other)
	{
		copyFrom(other);
	}

	return *this;
}

unsigned Log::getTimeElapsed() const
{
	return time.hours * 60 * 60 + time.minutes * 60 + time.seconds;
}

char Log::getType() const
{
	return type;
}

void Log::printSelf() const
{
	std::println("{}:{}:{} {} {}", time.hours, time.minutes, time.seconds, type, message);
}

Log::~Log()
{
	delete[] message;
	message = nullptr;
}

Log getFormattedLogInput()
{
	char buffer[1024];

	std::cin.getline(buffer, 1024);

	unsigned hours = (buffer[0] - '0') * 10 + (buffer[1] - '0');
	unsigned minutes = (buffer[3] - '0') * 10 + (buffer[4] - '0');
	unsigned seconds = (buffer[6] - '0') * 10 + (buffer[7] - '0');

	char type = buffer[9];

	char* message = new char[std::strlen(buffer) - 10];

	std::strcpy(message, buffer + 11);

	Log newLog(hours, minutes, seconds, type, message);

	return newLog;
}
