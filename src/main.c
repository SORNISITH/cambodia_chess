#include "board.h"
#include "global_main.h"
#include "layout.h"
#include "raylib.h"
#include <stdlib.h>

extern Vector2 board_cell_size;
extern struct SQ_CELL board_cell[ROW][COL];

int main(int argc, char* argv[])
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGH, "KHMER CHESS");
    layout_init();

    SetTargetFPS(60);
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
