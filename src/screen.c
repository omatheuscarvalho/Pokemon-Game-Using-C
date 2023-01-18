#include "player_info.h"

void welcome_screen(){
  printf("==================================\n\n");
  printf("             WELCOME              \n");
  printf("        TO A NEW POKEMON          \n");
  printf("        ADVENTURE IN UFJF         \n\n");
  printf("==================================\n");
  printf("\n\n\n\n\n");
  printf("Use 'a', 's', 'd', 'w' and enter to move\n");
  printf("Press enter to start\n");
  scanf("%*c");
  
}
void clear_chat(){
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
Player move_screen(Local map[H][L], Player new, Pokemon dex[]){
  printf("\n\n");
  printf("\n\n");
  new = make_move(map, new, dex);
  clear_chat();
  return new;
}
void city_menu(Local map[H][L], int x, int y){
  printf("==================================\n\n");
  printf("           YOU ARE IN              \n");
  printf("               %s              \n\n", map[x][y].name);
  printf("==================================\n");

  // Verify if the city was visited before
  if(map[x][y].visited == true){
    printf("You already have visited this city!\n");
  }else{
    printf("This is your first time at this city!\n");
  }
  printf("\n\n");
  print_map(map);
}
void gym_menu(Local map[H][L], int x, int y){
  printf("==================================\n\n");
  printf("           WELCOME TO              \n");
  printf("          A POKEMON GYM           \n\n");
  printf("==================================\n");

  // Verify if the gym was defeated
  if(map[x][y].defeated == true){
    printf("You already have defeated %s\n", map[x][y].name);
  }else{
    printf("The gym leadder %s is waiting you for a battle !!\n", map[x][y].name);
  }
  printf("\n\n");
  print_map(map);
}
void win_screen(){
  printf("==================================\n\n");
  printf("             CONGRATS!!              \n");
  printf("        YOU DEFEATED THE GAME          \n");
  printf("                =p                  \n\n");
  printf("==================================\n");
  printf("\n\n\n\n\n");
}