#include "Time.h"

Time::Time(const unsigned hours, const unsigned minutes, const unsigned seconds) : hours(hours), minutes(minutes), seconds(seconds)
{
}

Time& Time::operator=(const Time& other)
{
	if (this != &other)
	{
		hours = other.hours;
		minutes = other.minutes;
		seconds = other.seconds;
	}

	return *this;
}

unsigned Time::getTimeInSeconds() const
{
	return hours*60*60 + minutes * 60 + seconds * 60;
}
