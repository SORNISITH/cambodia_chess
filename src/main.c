#include "raylib.h"

int main(int argc, char* argv[])
{
    int W = 1200;
    int H = 900;
    InitWindow(W, H, "Simple game");
    bool pause = false;
    float ball_radius = 30.0f;
    Vector2 ball_pos = { (GetScreenWidth() / 2.0f), (GetScreenHeight() / 2.0f) };
    Vector2 ball_speed = { 5.0f, 4.0f };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            pause = !pause;
        }
        if (!pause) {
            ball_pos.x += ball_speed.x;
            ball_pos.y += ball_speed.y;

            if ((ball_pos.x >= (GetScreenWidth() - ball_radius)) || (ball_pos.x <= ball_radius)) {
                ball_speed.x *= -1.0f;
            }

            if ((ball_pos.y >= (GetScreenHeight() - ball_radius)) || (ball_pos.y <= ball_radius)) {
                ball_speed.y *= -0.95f;
            }
        }
        ClearBackground(RAYWHITE);
        BeginDrawing();
        {
            DrawCircleV(ball_pos, ball_radius, GOLD);
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
