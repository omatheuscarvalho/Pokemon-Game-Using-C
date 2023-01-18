#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "move.h"

Player set_new_player (Player new){
  // Fills the player section
  new.last_coord[0] = 3;
  new.last_coord[1] = 2;
  new.potion = 2;
  new.pokeball = 5;
  new.ultraball = 0;
  for(int i=0; i<4; i++){
    new.badges[i] = 0;
  }
  return new;
}
Player get_player_name(Player new){
  // NOT USED
  printf("What's your name ?\n");
  fgets(new.name, 50, stdin);
  printf("Welcome, %s", new.name);
  return new;
}
Player create_player(Player new){
  new = set_new_player(new);
  return new;
}