#include "layout.h"
#include "board.h"
#include "global_main.h"
#include "raylib.h"

float get_h_percent(float percent)
{
    return percent / 100 * SCREEN_HEIGH;
}
float get_w_percent(float percent)
{
    return percent / 100 * SCREEN_WIDTH;
}
struct Layout_Position {
    Vector2 pos;
    float w;
    float h;
};

void layout_init()
{
    int element[] = { 10, 80, 10 };
    int s = sizeof(element) / sizeof(element[0]);
    struct Layout_Position lay[s];

    for (int i = 0; i < s; ++i) {
        lay[i].pos.x = 0;
        lay[i].w = SCREEN_WIDTH;
        lay[i].h = get_h_percent(element[i]);
        if (i == 0) {
            lay[i].pos.y = 0;
        } else {
            lay[i].pos.y = lay[i - 1].pos.y + lay[i - 1].h;
        }
    }
    board_initilize_position(lay[1].pos, lay[1].w, lay[1].h);
}

void layout_display()
{
    board_display_grid();
}
