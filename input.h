#pragma once
#include <utility>


struct Coordinates
{
	int x;
	int y;
};


// Предоставляет методы для пользовательского ввода 
class Input
{
public:
	Input() = default;
	~Input() = default;
	Coordinates getMousePos();

};