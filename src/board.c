#include "board.h"
#include "global_main.h"
#include "raylib.h"
#include "string.h"
// struct SQ_CELL board_cell[ROW][COL];
struct BOARD main_board;
enum {
    MODE_SELECTION,
    MODE_VIEW,
};
int mode = MODE_VIEW;

Vector2 board_sq_size;
Vector2 board_cell_size;
Vector2 board_sq_init_position;

void board_set_kon_ouk(int row, int col, struct KON_OUK kon)
{
    board_cell[row][col].kon_ouk = kon;
}

void board_position_cell(Vector2 v_start, Vector2 v_size)
{
    struct SQ_CELL cell;
    board_cell_size = v_size;
    cell.pos = v_start;
    cell.size = v_size;
    for (int j = 0, charactor = 65; j < ROW; ++j, ++charactor) {
        cell.pos.x = v_start.x;
        for (int i = 0; i < COL; ++i) {
            char tmp_letter = charactor;
            char tmp_id = i + '0';
            if (((i + j) & 1) == 0) {
                cell.color = BOARD_COLOR_1;
            } else {
                cell.color = BOARD_COLOR_2;
            }
            cell.center.x = cell.pos.x + (cell.size.x / 2);
            cell.center.y = cell.pos.y + (cell.size.y / 2);
            cell.is_occupy = false;
            cell.is_select = false;
            cell.sqare.x = cell.pos.x;
            cell.sqare.y = cell.pos.y;
            cell.sqare.width = cell.size.x;
            cell.sqare.height = cell.size.y;
            cell.point.a = cell.pos;
            cell.point.b = (Vector2) { cell.pos.x + cell.sqare.width, cell.pos.y };
            cell.point.c = (Vector2) { cell.pos.x + cell.sqare.width, cell.pos.y + cell.sqare.height };
            cell.point.d = (Vector2) { cell.pos.x, cell.pos.y + cell.sqare.height };
            cell.id[0] = tmp_letter;
            cell.id[1] = tmp_id;
            cell.id[2] = '\0';
            board_cell[j][i] = cell;
            cell.pos.x += cell.size.x + BOARD_GAP;
        }
        cell.pos.y += cell.size.y + BOARD_GAP;
    }
}

void board_outline_cell(int row, int col, Color color)
{
    struct SQ_CELL t = board_cell[row][col];
    DrawLineV(t.point.a, t.point.b, BLACK);
    DrawLineV(t.point.b, t.point.c, BLACK);
    DrawLineV(t.point.c, t.point.d, BLACK);
    DrawLineV(t.point.d, t.point.a, BLACK);
}

void board_draw_cell(int row, int col)
{
    struct SQ_CELL t = board_cell[row][col];
    DrawRectangleV(t.pos, t.size, t.color);
    if (t.is_occupy) {
        DrawCircleV(t.center, board_cell_size.x / 2, RED);
    }
}

void board_initilize_position(Vector2 init_board_position, Vector2 size)
{
    float w = size.x;
    float h = size.y;
    int long_side = MAX(w, h);
    int short_side = MIN(w, h);

    Vector2 base_square_size = { (short_side / (float)ROW) - BOARD_GAP, (short_side / (float)COL) - BOARD_GAP };
    float x_gap = ((long_side - short_side) / 2.0);
    if (h <= w) {
        init_board_position.x = x_gap;
    } else {
        init_board_position.y = x_gap;
    }
    board_position_cell(init_board_position, base_square_size);
    board_sq_size = (Vector2) { short_side, short_side };
    board_sq_init_position = init_board_position;
}

void board_display_grid()
{
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            board_draw_cell(i, j);
        }
    }
}

void board_check_collision(Vector2 mouse_pos)
{
    if (mode == MODE_SELECTION) {
        return;
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        bool checked = false;
        for (int row = 0, rrow = 7; checked == false && row < ROW; ++row, --rrow) {
            for (int col = 0, ccol = 7; checked == false && col < COL; ++col, --ccol) {
                struct SQ_CELL* current_cell = &board_cell[row][col];
                if (CheckCollisionPointRec(mouse_pos, current_cell->sqare)) {
                    current_cell->is_occupy = true;
                    Vector2 nextMousePosition = GetMousePosition();

                    checked = true;
                } else if (CheckCollisionPointRec(mouse_pos, board_cell[rrow][ccol].sqare)) {
                    board_cell[rrow][ccol].is_occupy = true;
                    checked = true;
                }
            }
        }
    }
}
