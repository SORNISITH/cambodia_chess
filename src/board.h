#ifndef BOARD_H
#define BOARD_H
#include "raylib.h"

#define ROW 8
#define COL 8
#define BOARD_GAP 2
#define BOARD_COLOR_1 WHITE
#define BOARD_COLOR_2 GOLD

void board_initilize_position(Vector2 init_position, float w, float h);
void board_display_grid();
#endif
