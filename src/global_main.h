#ifndef GMAIN_H
#define GMAIN_H
// #define KHC_VERSION_MAJOR 0
// #define KHC_VERSION_MINOR 0
// #define KHC_VERSION_PATCH 0
// #define KHC_VERSION "0.0"
#include "raylib.h"
#include <stdint.h>
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGH 900

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

#endif // end my main
