#include "blinkingButton.h"

BlinkingButton::BlinkingButton(Dimensions dimensions, int textSizeX, int textSizeY, std::string texturePath, std::string label, int blinkingPeriodMs) :
	Button(dimensions, textSizeX, textSizeY, texturePath, label), blinkingPeriodMs(blinkingPeriodMs)
{
	startButtonBlinkTimer.StartTimer(blinkingPeriodMs);
}

void BlinkingButton::BlinkOnTimer()
{
	if (startButtonBlinkTimer.CheckIfTimerIsReady())
	{
		textColor = showsBlinkColor ? textColorMain : textColorBlink;
		showsBlinkColor = !showsBlinkColor;
		startButtonBlinkTimer.StartTimer(blinkingPeriodMs);
	}
}

