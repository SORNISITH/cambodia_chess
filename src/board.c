#include "board.h"
#include "global_main.h"
#include "raylib.h"

struct SQ_CELL board_cell[ROW][COL];
// void set_kon_ouk(int row, int col, struct KON_OUK kon)
// {
//     board_cell[row][col].kon_ouk = kon;
// }
void board_position_cell(Vector2 v_start, Vector2 v_size)
{
    struct SQ_CELL cell;
    cell.pos = v_start;
    cell.size = v_size;
    for (int j = 0; j < ROW; ++j) {
        cell.pos.x = v_start.x;

        for (int i = 0; i < COL; ++i) {
            if (((i + j) & 1) == 0) {
                cell.color = BOARD_COLOR_1;
            } else {
                cell.color = BOARD_COLOR_2;
            }
            cell.sqare.x = cell.pos.x;
            cell.sqare.y = cell.pos.y;
            cell.sqare.width = cell.size.x;
            cell.sqare.height = cell.size.y;
            cell.center.x = cell.pos.x + (cell.size.x / 2);
            cell.center.y = cell.pos.y + (cell.size.y / 2);
            cell.is_occupy = false;
            board_cell[j][i] = cell;
            cell.pos.x += cell.size.x - BOARD_GAP;
        }

        cell.pos.y += cell.size.y - BOARD_GAP;
    }
}

void board_draw_cell(int row, int col)
{
    struct SQ_CELL t = board_cell[row][col];
    DrawRectangleV(t.pos, t.size, t.color);
    DrawLineV(t.pos, t.size, BLUE);
}

void board_initilize_position(Vector2 init_board_position, float w, float h)
{
    int long_side = MAX(w, h);
    int short_side = MIN(w, h);

    Vector2 base_square_size = { (short_side / (float)ROW), (short_side / (float)COL) };
    float x_gap = ((long_side - short_side) / 2.0);
    if (h <= w) {
        init_board_position.x = x_gap;
    } else {
        init_board_position.y = x_gap;
    }

    board_position_cell(init_board_position, base_square_size);
}

void board_display_grid()
{
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            board_draw_cell(i, j);
        }
    }
}
