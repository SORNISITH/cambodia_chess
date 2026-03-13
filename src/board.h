#ifndef BOARD_H
#define BOARD_H
#include "global_main.h"
#define ROW 8
#define COL 8
#define BOARD_GAP 1
#define BOARD_COLOR_1 WHITE
#define BOARD_COLOR_2 GOLD

void board_initilize_position(Vector2 init_position, Vector2 size);
void board_display_grid();
void board_outline_cell(int row, int col, Color color);
void board_check_collision(Vector2 mouse_pos);
void board_set_kon_ouk(int row, int col, struct KON_OUK kon);

#endif
