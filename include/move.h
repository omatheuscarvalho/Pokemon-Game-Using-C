#include "map.h"

void coords(int coord[2], char direction);
bool can_move(Local map[H][L], int coords[2], Player new);
void change_marks(Local map[H][L]);
void went_city(Local map[H][L], Player new);
Player make_move(Local map[H][L], Player p, Pokemon dex[]);
