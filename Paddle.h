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
    DrawRectangle(x, y, width, height, color);
  }

  void update() {
    if (IsKeyDown(KEY_UP)) {
      y -= speed;
    } else if (IsKeyDown(KEY_DOWN)) {
      y += speed;
    }

    if (y < 0) {
      y = 0;
    } else if (y + height > GetScreenHeight()) {
      y = GetScreenHeight() - height;
    }
  }
};

class CPUPaddle : public Paddle {
public:
  CPUPaddle(float x, float y, float speed) : Paddle(x, y, speed) {}

  void update(int ballY) {
    if (y + height/2 > ballY) {
      y -= speed;
    } else if (y + height/2 < ballY) {
      y += speed;
    }

    if (y < 0) {
      y = 0;
    } else if (y + height > GetScreenHeight()) {
      y = GetScreenHeight() - height;
    }
  }
};
