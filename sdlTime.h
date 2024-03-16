#pragma once
#include <SDL.h>

// ��������� ������, ��������� �� �������� ��������� �����
class Time
{
private:
    static double deltaTime;
    static Uint64 NOW, LAST;

public:
    // ���������� � ����� ��������� ����� ��� ���������� ������� ���������
    static void Calculate(void);
    // ���������� � ������ ��������� ����� ��� ���������� ������� ���������
    static void SetNow(Uint64 _NOW);
    // ���������� ����� ��������� ���������� �����
    static double GetDeltaTime();
};