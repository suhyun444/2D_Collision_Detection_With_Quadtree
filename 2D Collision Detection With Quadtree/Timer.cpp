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
	elapsedMS = 0;
	return true;
}

void Timer::Frame()
{
	INT64 currentTime;
	float timeDifference;
	frameCount++;
	timeElapsed += GetTime() / 1000;
	elapsedMS += GetTime();
	//std::cout << elapsedMS / frameCount << "\n";
	if (timeElapsed >= 10.0f)
	{
		timeElapsed -= 10.0f;
		frame = frameCount;
		std::cout << elapsedMS / frameCount;
		frameCount = 0;
	}
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	timeDifference = (float)(currentTime - startTime);
	frameTime = timeDifference / ticksPerMs;

	startTime = currentTime;

	return;
}
void Timer::UpdateTime()
{
	INT64 currentTime;
	float timeDifference;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	timeDifference = (float)(currentTime - startTime);
	frameTime = timeDifference / ticksPerMs;

	startTime = currentTime;
}
float Timer::GetTime()
{
	return frameTime;
}
int Timer::GetFramePerSecond()
{
	return frame;
}