#include "Timer.h"

Timer::Timer()
{
	
}
Timer::~Timer()
{

}
bool Timer::Initialize()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
	if (frequency == 0)
	{
		return false;
	}

	ticksPerMs = (float)(frequency / 1000);

	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);
	frameCount = 0;
	frame = 0;
	timeElapsed = 0;
	return true;
}

void Timer::Frame()
{
	INT64 currentTime;
	float timeDifference;
	frameCount++;
	timeElapsed += GetTime() / 1000;
	if (timeElapsed >= 1.0f)
	{
		timeElapsed -= 1.0f;
		frame = frameCount;
		frameCount = 0;
	}
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	timeDifference = (float)(currentTime - startTime);

	frameTime = timeDifference / ticksPerMs;

	startTime = currentTime;

	return;
}

float Timer::GetTime()
{
	return frameTime;
}
int Timer::GetFramePerSecond()
{
	return frame;
}