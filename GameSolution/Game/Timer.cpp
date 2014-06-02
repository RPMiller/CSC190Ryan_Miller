#include "Timer.h"


Timer::Timer(void)
{
	QueryPerformanceFrequency(&clockFrequency);
}


Timer::~Timer(void)
{
}


void Timer::Start()
{
	QueryPerformanceCounter(&startTicks);
}
	
float Timer::Stop()
{
	LARGE_INTEGER delta;
	LARGE_INTEGER endTicks;
	QueryPerformanceCounter(&endTicks);
	delta.QuadPart = endTicks.QuadPart - startTicks.QuadPart;
	return (float)delta.QuadPart / clockFrequency.QuadPart;
}
	
float Timer::Interval()
{
	LARGE_INTEGER delta;
	LARGE_INTEGER nextTick;
	QueryPerformanceCounter(&nextTick);
	delta.QuadPart = nextTick.QuadPart - lastIntervalTicks.QuadPart;
	lastIntervalTicks = nextTick;
	return (float)delta.QuadPart / clockFrequency.QuadPart;
}