#include "fpsCounter.h"

FpsCounter::FpsCounter()
{
	oneSecondTimer.StartTimer(1000);
}

void FpsCounter::ProceedCount()
{
	renderedFramesInLastSecond++;
	if (oneSecondTimer.CheckIfTimerIsReady())
	{
		lastFps = renderedFramesInLastSecond;
		renderedFramesInLastSecond = 0;
		oneSecondTimer.StartTimer(1000);
	}
}
