#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "dex.h"
/* 
This section include functions to manipulate the main map
Maps infos: 
-> 8 hight, 11 length
-> Normal gym leaders: 0,0; 7,0; 3,10
-> Final leader: 7,10
*/
void create_local(Local map[H][L], int h, int l, char name[50], char local_type, char mon_type[20], int dex, char symbol){
  // This function fills the map 
  strcpy(map[h][l].name, name);
  map[h][l].local_type = local_type;
  strcpy(map[h][l].mon_type, mon_type);
  map[h][l].dex_num_localmon = dex;
  //map[h][l].defeated = defeated;
  //map[h][l].visited = visited;
  map[h][l].symbol = symbol;
}
void blank_map (Local map[H][L]){
  // This function set all the basic predefinition for the map
  for(int i=0;i<H;i++){
    for(int j=0;j<L; j++){
      map[i][j].defeated = false;
      map[i][j].visited = false;
      map[i][j].symbol = ' ';
      map[i][j].local_type = 'B';
      
    }
  }
}
void create_path_upper(Local map[H][L], int x, int y){
  map[x][y].symbol = '|';
}
void create_path_down(Local map[H][L], int x, int y){
  map[x][y].symbol = '-';
}

void create_main_map (Local map[H][L]){
  // Define all locals for the main map as blank
  blank_map(map);
  
  // Define Gym leaders:
  create_local(map, 0, 0, "Igor Knap", 'G', "Grass", 12, '&');
  create_local(map, 7, 0, "Glauker Brasilia", 'G', "Ghost", 13, '%');
  create_local(map, 3, 10, "No Logic Lucianne", 'G', "Psychic", 14, '$');
  create_local(map, 7, 10, "Carlos Function", 'G', "Steel", 15, '@');
  
  // Define the cities
  create_local(map, 3, 2, "ICE", 'C', "POKETYPE", 1, 'X'); // the initial place
  map[3][2].visited = true;
  map[3][2].defeated = true;
  
  create_local(map, 3, 0, "ICC", 'C', "POKETYPE", 2, '#');
  create_local(map, 0, 2, "RU", 'C', "POKETYPE", 3, '#');
  create_local(map, 1, 5, "FE", 'C', "POKETYPE", 4, '#');
  create_local(map, 3, 5, "FAU", 'C', "POKETYPE", 5, '#');
  create_local(map, 3, 8, "IAD", 'C', "POKETYPE", 6, '#');
  create_local(map, 1, 8, "IE", 'C', "POKETYPE", 7, '#');
  create_local(map, 5, 10, "ICB", 'C', "Gras", 8, '#');
  create_local(map, 5, 4, "FO", 'C', "POKETYPE", 9, '#');
  create_local(map, 7, 4, "FM", 'C', "POKETYPE", 10, '#');
  create_local(map, 7, 2, "FACOM", 'C', "POKETYPE", 11, '#');
  create_local(map, 7, 7, "ICH", 'C', "POKETYPE", 12, '#');

  // creating the path |
  create_path_upper(map, 1, 0);
  create_path_upper(map, 2,0);
  create_path_upper(map, 1,2);
  create_path_upper(map, 2,2);
  create_path_upper(map, 4,2);
  create_path_upper(map, 5,2);
  create_path_upper(map, 6,2);
  create_path_upper(map, 6,4);
  create_path_upper(map, 2,5);
  create_path_upper(map, 2,8);
  create_path_upper(map, 4,10);

  // create the path -
  create_path_down(map, 3,1);
  create_path_down(map, 3,3);
  create_path_down(map, 3,4);
  create_path_down(map, 3,6);
  create_path_down(map, 3,7);
  create_path_down(map, 3,9);
  create_path_down(map, 1,6);
  create_path_down(map, 1,7);
  create_path_down(map, 5,5);
  create_path_down(map, 5,6);
  create_path_down(map, 5,7);
  create_path_down(map, 5,8);
  create_path_down(map, 5,9);
  create_path_down(map, 7,1);
  create_path_down(map, 7,3);
  create_path_down(map, 7,5);
  create_path_down(map, 7,6);
  create_path_down(map, 7,8);
  create_path_down(map, 7,9);
}
void print_map (Local map[H][L]){
  // Prints the map
  for(int i=0;i<H;i++){
    for(int j=0;j<L; j++){
      printf("%c ", map[i][j].symbol);
      
    }
    printf("\n");
  }
}
