#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#define L 11
#define H 8

#ifndef STRUCT_H
#define STRUCT_H
typedef struct{
  char local_type; 
  // G: gym, C: city, B: blank
  char name[50];
  char mon_type[20];
  int dex_num_localmon;
  bool defeated;
  bool visited;
  char symbol;
} Local;

typedef struct{
  char name[50];
  int last_coord[2];
  int pokemon_got[16];
  float money;
  int potion;
  int pokeball;
  int ultraball;
  int badges[4]; // each one has a number
  bool last_battle;
} Player;

typedef struct{
  char name[50];
  int hp;
  int damage;
  int type; // Only using Fire(0), grass(1), ground(2), eletric(3), water(4) and Ghost(5)
} Pokemon;

//Creating the dex

#endif // struct