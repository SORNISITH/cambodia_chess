#include "global_main.h"
#include "layout.h"
int main(int argc, char* argv[])
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGH, "KHMER CHESS");
    SetTargetFPS(60);
    layout_init();
    while (!WindowShouldClose()) {
        Vector2 mouse_pos = GetMousePosition();
        ClearBackground(RAYWHITE);
        BeginDrawing();
        {
            layout_display();
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
