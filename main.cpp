#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"

int main (void) {
    const int windowHeight = 720;
    const int windowWidth = 1280;

    InitWindow(windowWidth, windowHeight, "Pong");
    SetTargetFPS(60);

    Paddle paddle(10, windowHeight / 2 - 60, 7.0f);
    Ball ball(windowWidth / 2, windowHeight / 2, 20);

    while(!WindowShouldClose()){
	ball.update();
        
	BeginDrawing();

        ClearBackground(WHITE);

	DrawLine(windowWidth / 2, 0, windowWidth / 2, windowHeight, BLUE);
	ball.draw();
	paddle.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
