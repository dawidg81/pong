#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"

int main (void) {
  const int windowHeight = 720;
  const int windowWidth = 1280;
  const float paddlesSpeed = 7.0f;

  InitWindow(windowWidth, windowHeight, "Pong");
  SetTargetFPS(60);

  Paddle paddle(10, windowHeight / 2 - 60, paddlesSpeed);
  CPUPaddle cpuPaddle(windowWidth - 35, windowHeight / 2 - 60, paddlesSpeed);
  Ball ball(windowWidth / 2, windowHeight / 2, 20);

  while(!WindowShouldClose()){
    ball.update();
    paddle.update();
    cpuPaddle.update(ball.y);

    if (CheckCollisionCircleRec(
            Vector2{ball.x, ball.y}, ball.radius,
            Rectangle{paddle.x, paddle.y, paddle.width, paddle.height})) {
      ball.speedX *= -1;
    }

    if (CheckCollisionCircleRec(
            Vector2{ball.x, ball.y}, ball.radius,
            Rectangle{cpuPaddle.x, cpuPaddle.y, cpuPaddle.width, cpuPaddle.height})) {
      ball.speedX *= -1;
    }

    BeginDrawing();

    ClearBackground(WHITE);

    DrawLine(windowWidth / 2, 0, windowWidth / 2, windowHeight, BLUE);
    ball.draw();
    paddle.draw();
    cpuPaddle.draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
