#pragma once
#include "timer.h"

// ������� ������ � �������
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