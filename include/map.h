#include "dex.h"


void create_local(Local map[H][L], int h, int l, char name[50], char local_type, char mon_type[20], int dex, char symbol);
void blank_map (Local map[H][L]);
void create_path_upper(Local map[H][L], int x, int y);
void create_path_down(Local map[H][L], int x, int y);
void create_main_map (Local map[H][L]);
void print_map (Local map[H][L]);