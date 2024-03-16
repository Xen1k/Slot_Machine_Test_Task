#pragma once
#include <SDL.h>

// Реализует методы, связанные со временем отрисовки кадра
class Time
{
private:
    static double deltaTime;
    static Uint64 NOW, LAST;

public:
    // Вызывается в конце отрисовки кадра для вычисление времени отрисовки
    static void Calculate(void);
    // Вызывается в начале отрисовки кадра для вычисление времени отрисовки
    static void SetNow(Uint64 _NOW);
    // Возвращает время отрисовки последнего кадра
    static double GetDeltaTime();
};