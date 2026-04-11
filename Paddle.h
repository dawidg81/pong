#pragma once
#include "raylib.h"

class Paddle {
public:
	float x, y, width, height, speed;
	Color color;

	Paddle(float _x, float _y, float _speed){
		x = _x;
		y = _y;
		speed = _speed;
		width = 25;
		height = 120;
		color = BLACK;
	}

	void draw(){
		DrawRectangle(x, y, x + width, y + height, color);
	}

	void update(){
	}
};
