#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "map.h"
#include "battle.h"

/*
This section has all the movimentations funcionalities
The possible moves are:
* if there's a path in the side that the player choosed
* if its true, the player will continue in that direction until he gets a city
* Than the last city must be marked as visited and changed the symbol from '# to '+'
* And the currently city must be changed from '#' to 'X', witch indicates that the player is there
* And if theres no path, the error massage appears

'
*/
void coords(int coord[2], char direction){
  // Realize the moves inside the map array
  if(direction == 'D' || direction == 'd'){
    coord[1]= 1;
  }else if(direction == 'A' || direction == 'a'){
    coord[1]=-1;
  }else if(direction == 'W' || direction == 'w'){
    coord[0]=-1;
  }else if(direction == 'S' || direction == 's'){
    coord[0]=1;
  }
}
bool can_move(Local map[H][L], int coords[2], Player new){
  // check if has a path through that direction
  int x, y;
  x = new.last_coord[0] + coords[0];
  y = new.last_coord[1] + coords[1];
  
  // Verify if there's a path in the new coords.
  if(map[x][y].symbol == '-' || map[x][y].symbol == '|'){
    return true;
  }else{
    return false;
  }
}
void change_marks(Local map[H][L]){
  // find the X, set to -> + & visited
  int x, y;
  for(int i=0;i<H;i++){
    for(int j=0;j<L;j++){
      if(map[i][j].symbol == 'X'){
        map[i][j].symbol = '+';
        map[i][j].visited = true;
      }
    }
  }
}
void went_city(Local map[H][L], Player new){
  // Just change the new position symbol to 'X'
  int x = new.last_coord[0];
  int y = new.last_coord[1];

  map[x][y].symbol = 'X';
}
Player make_move(Local map[H][L], Player p, Pokemon dex[]){
  p.last_battle = false; // Used for badges and caputre features
  int coord[2] = {0,0};
  char direction;
  int badg = 0;
  
  // Check if the pokemon of the city or gym was defeated
  if(map[p.last_coord[0]][p.last_coord[1]].defeated == false){
    if(map[p.last_coord[0]][p.last_coord[1]].local_type == 'C'){
      printf("[c] Battle city's pokemon\n");
    }
    // Checking for final leadder
    else if(p.last_coord[0]==7 && p.last_coord[1]== 10){
        // Verify if the player has 3 badges
        for(int i=0;i<4;i++){
          if(p.badges[i] != -1){
            badg+= 1;
          }
        }
        if(badg == 3){
          printf("[c] Battle the final gym leadder\n");
        }
        else{
          printf("[-] You need at least 3 badges to battle the final leadder!\n");
        }
    }
    else if(map[p.last_coord[0]][p.last_coord[1]].local_type == 'G'){
      printf("[c] Battle gym leadder\n");
    }
  }else if(map[p.last_coord[0]][p.last_coord[1]].defeated == true){
    if(map[p.last_coord[0]][p.last_coord[1]].local_type == 'C'){
      printf("[!] You have already captured the city's pokemon!\n");
    }else if(map[p.last_coord[0]][p.last_coord[1]].local_type == 'G'){
      printf("[!] You have already defeated this gym.\n");
    }
  }
  // Prints the menu
  printf("[h] Heal the team.\n");
  printf("[j] Pokedex view\n");
  printf("[m] Change pokemon order\n");
  printf("[ ] Were do you wanna go?\n");
  
  scanf("%c", &direction);
  // Checks the options
  // View the player Dex
  if(direction == 'j' ||  direction == 'J'){
    clear_chat();
    print_player_dex(p, dex);
    sleep(5);
  }
    
  // Change the mon order
  else if(direction == 'm' ||  direction == 'M'){
    p = mon_order_changer(p);
  }
    
  // Heal the team
  else if(direction == 'h' ||  direction == 'H'){
    clear_chat();
    heal_poke(p, dex);
    printf("Healing all pokemon!\n");
    sleep(2);
    printf("Ready to FIGHT!!\n");
    sleep(2);
  }
    
  // The battle Feature for city
  else if(map[p.last_coord[0]][p.last_coord[1]].defeated == false &&(direction == 'c' || direction == 'C')){
    // If is not the last gym -> fight
    // If is and has 3 badges -> fight
    if(p.last_coord[0] !=7 || p.last_coord[1] !=10){
        p = battle(p, dex, map[p.last_coord[0]][p.last_coord[1]].dex_num_localmon, map);
    }else{
      if(badg == 3){
        p = battle(p, dex, map[p.last_coord[0]][p.last_coord[1]].dex_num_localmon, map);
      }
    }

    // Verify if the player defeatd the mon, if true, caputre
    if(p.last_battle == true && map[p.last_coord[0]][p.last_coord[1]].local_type == 'C'){
      printf("You defeated %s\n", dex[map[p.last_coord[0]][p.last_coord[1]].dex_num_localmon].name);
      printf("Capturing...\n");
      sleep(2);
      printf("%s CAPTURED!\n", dex[map[p.last_coord[0]][p.last_coord[1]].dex_num_localmon].name);
      sleep(2);  
      
      // find an empty slot in player dex and add the pokemon
      for(int i=1;i!=-1;i++){
        if(p.pokemon_got[i]== -1){
          p.pokemon_got[i] = map[p.last_coord[0]][p.last_coord[1]].dex_num_localmon;
          i = -1;
          break;
        }
      } 
    }
    // Verify if the player defeated the leadder if true, new badge
    else if(p.last_battle == true && map[p.last_coord[0]][p.last_coord[1]].local_type == 'G'){
      printf("You defeated %s!\n", map[p.last_coord[0]][p.last_coord[1]].name);
      sleep(1);
      printf("New Badge added!\n");
      sleep(2);
      for(int i=0;i<4;i++){
        if(p.badges[i]==-1){
          p.badges[i] = 1;
          break;
        }
      }
    }
  }
  else{
      coords(coord, direction);
    // if the path exists, it will continue walinking until gets a city
    if(can_move(map, coord, p) == true){
      for(int i=1; i>0; i++){
        p.last_coord[0] += coord[0];
        p.last_coord[1] += coord[1];
        // verify if the new coord is a city or gym;
        if(map[p.last_coord[0]][p.last_coord[1]].local_type== 'C' || map[p.last_coord[0]][p.last_coord[1]].local_type== 'G'){
          i=-1;
        } 
      }
      
      // remove the X and put a +
        change_marks(map);
        // put the new X
        went_city(map, p);
    }
  }
  return p;
}
