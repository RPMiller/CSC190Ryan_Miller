#pragma once
#include<window.h>

class Timer
{
	LARGE_INTEGER clockFrequency;
	LARGE_INTEGER startTicks;
	LARGE_INTEGER lastIntervalTicks;
public:
	Timer(void);
	~Timer(void);
	void Start();
	float Stop();
	float Interval();
};

