#pragma once
struct Time
{
	unsigned hours = 0;
	unsigned minutes = 0;
	unsigned seconds = 0;

	Time() = default;
	Time(const unsigned hours, const unsigned minutes, const unsigned seconds);
	Time& operator=(const Time& other);

	unsigned getTimeInSeconds() const;
};
