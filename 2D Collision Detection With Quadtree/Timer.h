#pragma once
#include <Windows.h>
#include <iostream>

class Timer
{
private:
	INT64 frequency;
	float ticksPerMs;
	INT64 startTime;
	float frameTime;
	float timeElapsed;
	int frameCount;
	int frame;
	long long elapsedMS;
public:
	Timer();
	~Timer();

	void UpdateTime();
	bool Initialize();
	void Frame();
	float GetTime();
	int GetFramePerSecond();
};