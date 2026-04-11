#include "raylib.h"
#include "Ball.h"

int main (void) {
    const int windowHeight = 720;
    const int windowWidth = 1280;

    InitWindow(windowWidth, windowHeight, "Pong");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(WHITE);

	DrawCircle(windowWidth / 2, windowHeight / 2, windowHeight / 2, BLACK);
	DrawRectangle(windowWidth / 2, windowHeight / 2, windowWidth, windowHeight, RED);
	DrawLine(0, windowHeight, windowWidth, 0, GREEN);
	DrawLine(0, 0, windowWidth, windowHeight, BLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
