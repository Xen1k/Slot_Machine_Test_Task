#pragma once
#include "timer.h"

// —чЄтчик кадров в секунду
class FpsCounter
{
private:
	int lastFps = 0;
	int renderedFramesInLastSecond = 0;
	Timer oneSecondTimer;
public:
	FpsCounter();
	void ProceedCount();
	inline int GetLastFps() const { return lastFps; }
};