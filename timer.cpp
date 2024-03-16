#include "timer.h"

void Timer::StartTimer(int timerMsDuration)
{
	startTime = std::chrono::system_clock::now();
	this->timerMsDuration = timerMsDuration;
}

bool Timer::CheckIfTimerIsReady()
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime);
	return milliseconds.count() > timerMsDuration;
}
