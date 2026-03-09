#include "raylib.h"
#include <stdint.h>
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGH 900
#define ROW 8
#define COL 8
#define BOARD_GAP 2
#define BOARD_COLOR_1 WHITE
#define BOARD_COLOR_2 GOLD

#define MAX(a, b) ((a) >= (b) ? (a) : (b));
#define MIN(a, b) ((a) < (b) ? (a) : (b));

enum Player_type {
    OBSERVER,
    PLAYER1,
    PLAYER2,
};
enum Kon_type {
    KON_KING,
    KON_QUEEN,
    KON_TOUK,
    KON_SES,
    KON_KOUL,
    KON_NEANG,
    KON_TREY,
    KON_TREY_BOAK
};

struct Player {
    enum Player_type type;
    char* name;
    uint64_t id;
};

struct KON_OUK {
    enum Kon_type kon_type;
    struct Player player_owned;
    uint64_t id;
};

struct SQ_CELL {
    Rectangle sqare;
    Vector2 pos;
    Vector2 size;
    Vector2 center;
    Color color;
    bool is_occupy;
    struct KON_OUK kon_ouk;
};

static struct SQ_CELL board_cell[ROW][COL];

void set_kon_ouk(int row, int col, struct KON_OUK kon)
{
    board_cell[row][col].kon_ouk = kon;
}

void khc_main_layout()
{
    int w = GetScreenWidth();
    int h = GetScreenHeight();
}
void khc_draw_grid();
void khc_draw_cell(int row, int col);
void khc_init_board_cell(Vector2 v_start, Vector2 v_size);
void khc_init_board();
int main(int argc, char* argv[])
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGH, "KHMER CHESS");
    SetTargetFPS(60);
    khc_init_board();
    int x = 1;
    while (!WindowShouldClose()) {
        Vector2 mouse_pos = GetMousePosition();
        if ((CheckCollisionPointRec(mouse_pos, board_cell[0][0].sqare)) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {
            // set_kon_ouk(0, 0, KON_KING);
        }
        ClearBackground(RAYWHITE);
        BeginDrawing();
        {
            //  khc_draw_grid();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void khc_draw_grid()
{
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            khc_draw_cell(i, j);
        }
    }
}
void khc_init_board_cell(Vector2 v_start, Vector2 v_size)
{
    struct SQ_CELL cell;
    cell.pos = v_start;
    cell.size = v_size;
    for (int j = 0; j < ROW; ++j) {

        cell.pos.x = v_start.x;

        for (int i = 0; i < COL; ++i) {
            if ((i + j & 1) == 0) {
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
            cell.pos.x += cell.size.x + BOARD_GAP;
        }

        cell.pos.y += cell.size.y + BOARD_GAP;
    }
}
void khc_init_board()
{
    int long_side = MAX(SCREEN_HEIGH, SCREEN_WIDTH);
    int short_side = MIN(SCREEN_HEIGH, SCREEN_WIDTH);

    Vector2 base_square_size = { (short_side / (float)ROW), (short_side / (float)COL) };
    float x_gap = ((long_side - short_side) / 2.0);
    Vector2 init_board_position = { 0, 0 };
    if (SCREEN_HEIGH <= SCREEN_WIDTH) {
        init_board_position.x = x_gap;
    } else {
        init_board_position.y = x_gap;
    }
    khc_init_board_cell(init_board_position, base_square_size);
}

void khc_draw_cell(int row, int col)
{
    struct SQ_CELL t = board_cell[row][col];
    DrawRectangleV(t.pos, t.size, t.color);
}
