#pragma once
#include <chrono>

class Timer
{
private:
	std::chrono::time_point<std::chrono::system_clock> startTime;
	int timerMsDuration = 0;
public:
	Timer() = default;
	~Timer() = default;
	void StartTimer(int timerMsDuration);
	bool CheckIfTimerIsReady();
};