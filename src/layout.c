#include "layout.h"
#include "board.h"
#include "global_main.h"
#include "raylib.h"
#include <stdio.h>

extern struct SQ_CELL board_cell[ROW][COL];
extern Vector2 board_sq_size;
extern Vector2 board_sq_init_position;

float get_h_percent(float percent)
{
    return percent / 100 * SCREEN_HEIGH;
}
float get_w_percent(float percent)
{
    return percent / 100 * SCREEN_WIDTH;
}

struct Layout_Position {
    Vector2 start_pos;
    Vector2 size;
};
struct Layout_Position Position_Layout_1[3];

void layout_generate(struct Layout_Position* pl, int element_count)
{
    int element[] = { 10, 80, 10 };
    for (int i = 0; i < element_count; ++i) {
        pl[i].start_pos.x = 0;
        pl[i].size.x = SCREEN_WIDTH;
        pl[i].size.y = get_h_percent(element[i]);
        if (i == 0) {
            pl[i].start_pos.y = 0;
        } else {
            pl[i].start_pos.y = pl[i - 1].start_pos.y + pl[i - 1].size.y;
        }
    }
    board_initilize_position(pl[1].start_pos, pl[1].size);
}

void layout_init()
{
    layout_generate(Position_Layout_1, 3);
}

void layout_display_1()
{
    DrawRectangleV(Position_Layout_1[0].start_pos, Position_Layout_1[0].size, RED);
    board_display_grid();
    DrawRectangleV(Position_Layout_1[2].start_pos, Position_Layout_1[2].size, RED);
}
