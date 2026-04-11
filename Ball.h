#pragma once
#include "raylib.h"

class Ball {
public:
	float x, y, speedX, speedY;
	int radius;
	Color color;

	Ball(float _x, float _y, int _radius){
		x = _x;
		y = _y;
		radius = _radius;
		speedX = 7.0f;
		speedY = 7.0f;
		color = BLACK;
	}

	void draw(){
		DrawCircle(x, y, radius, color);
	}
};
