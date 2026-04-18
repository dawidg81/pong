#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include <string>

int playerScore = 0;
int cpuScore = 0;

int main (void) {
  const int windowHeight = 720;
  const int windowWidth = 1280;
  const float paddlesSpeed = 5.0f;

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

    if (ball.x + ball.radius > windowWidth) {
      playerScore++;
      ball.reset();
    } else if (ball.x - ball.radius < 0) {
      cpuScore++;
      ball.reset();
    }

    BeginDrawing();

    ClearBackground(WHITE);

    DrawLine(windowWidth / 2, 0, windowWidth / 2, windowHeight, BLUE);
    ball.draw();
    paddle.draw();
    cpuPaddle.draw();
    DrawText(TextFormat("%i", playerScore), windowWidth / 4 - 20, 20, 80, BLACK);
    DrawText(TextFormat("%i", cpuScore), 3 * windowWidth / 4 - 20, 20, 80, BLACK);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
