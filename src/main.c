#include "board.h"
#include "global_main.h"
#include "layout.h"
#include "raylib.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGH, "KHMER CHESS");
    SetTargetFPS(60);
    layout_init();
    int current_layout = 1;

    while (!WindowShouldClose()) {
        Vector2 mouse_pos = GetMousePosition();
        ClearBackground(RAYWHITE);
        board_check_collision(mouse_pos);
        BeginDrawing();
        {
            switch (current_layout) {
            case 1:
                layout_display_1();
                break;
            }
        }
        EndDrawing();
    }
    CloseWindow();
    system("rm main");
    return 0;
}
