#pragma once
#include <utility>


struct Coordinates
{
	int x;
	int y;
};


// ������������� ������ ��� ����������������� ����� 
class Input
{
public:
	Input() = default;
	~Input() = default;
	Coordinates getMousePos();

};