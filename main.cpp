#include "raylib.h"
#include "Ball.h"

int main (void) {
    const int windowHeight = 720;
    const int windowWidth = 1280;

    InitWindow(windowWidth, windowHeight, "Pong");
    SetTargetFPS(60);

    Ball ball(windowWidth / 2, windowHeight / 2, 20);

    while(!WindowShouldClose()){
	ball.update();
        
	BeginDrawing();

        ClearBackground(WHITE);

	ball.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
