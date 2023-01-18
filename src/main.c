#include <stdio.h>
#include "battle.h"
/*
  Matheus Carvalho Torres
  matheus.torres@estudante.ufjf.br
  Erik Magalhães de Souza
  erikmagalhaes.souza@estudante.ufjf.br
*/
int main(int argc, char **argv) {
  
  // Creating the map for the game
  Local map[H][L];
  create_main_map(map);

  //Create the PokeDex
  Pokemon dex[16];
  create_dex(dex);
  
  // Run the game
  welcome_screen();
  clear_chat();
  
  // Create the player info
  Player new;
  new = create_player(new);

  // Setting the pokemon got and badges to -1 and giving the first mon
  // The -1 value means Empty
  new = zero_mon(new);
  new.pokemon_got[0] = 0; // Bulbasaur

  // Increasse bulbasaur damage for testing
  dex[0].damage = 2;

  // Play until return win true
  // Win true means 4 gym badges
  bool win = false;
  while(win !=true){
    
    // Verify if its a city
    if(map[new.last_coord[0]][new.last_coord[1]].local_type == 'C'){
      
      // If its true, print the city screen
      city_menu(map, new.last_coord[0], new.last_coord[1]);
    }
      
      // If not, print the gym screen 
    else{
      gym_menu(map, new.last_coord[0], new.last_coord[1]);
    }
    
    // Run the move section
    new = move_screen(map, new, dex);

    // Check if the player Has 4 badges
    int badges = 0;
    for(int i=0;i<4;i++){
      if(new.badges[i] != -1){
        badges += 1;
      }
    }
    if(badges == 4){
      win = true;
      clear_chat();
      win_screen();
      printf("\n");
    }
  }
  return 0;
}