#import "struct.h"

void print_type(int num){
  // Just print the pokemon Type
  if(num == 0){
    printf("Fire");
  }else if(num == 1){
    printf("Grass");
  }else if(num == 2){
    printf("Ground");
  }else if(num == 3){
    printf("Electric");
  }else if(num == 4){
    printf("Water");
  }else if(num == 5){
    printf("Ghost");
  }
}
void save_poke(Pokemon dex[], int dex_number, char name[], int hp, int damage, int type){
  // This function fill the pokedex
  strcpy(dex[dex_number].name, name);
  dex[dex_number].type = type;
  dex[dex_number].damage = damage;
  dex[dex_number].hp = hp;  
}
void create_dex(Pokemon dex[]){
  // Only using Fire(0), grass(1), ground(2), eletric(3), water(4) and Ghost(5)
  // Creating the dex using the fill function
  save_poke(dex, 0, "Bulbasaur", 10, 2, 1);
  save_poke(dex, 1, "Psyduck", 10, 2, 4);
  save_poke(dex, 2, "Pikachu", 10, 2, 3);
  save_poke(dex, 3, "Vulpix", 10, 2, 0);
  save_poke(dex, 4, "Diglet", 10, 2, 2);
  save_poke(dex, 5, "Growlithe", 10, 2, 0);
  save_poke(dex, 6, "Bellsprout", 10, 2, 1);
  save_poke(dex, 7, "Geodude", 10, 2, 2);
  save_poke(dex, 8, "Magnamite", 10, 2, 3);
  save_poke(dex, 9, "Tangela", 10, 2, 1);
  save_poke(dex, 10, "Staryu", 10, 2, 4);
  save_poke(dex, 11, "Charmander", 10, 2, 0);
  save_poke(dex, 12, "Onix", 20, 3, 2);
  save_poke(dex, 13, "Charizard", 20, 3, 0);
  save_poke(dex, 14, "Exeggutor", 20, 3, 1);
  save_poke(dex, 15, "MEGA Gengar", 30, 4, 5);
}
void printf_dex(Pokemon dex[]){
  // Just a test function to print all the pokedex
  printf("-----------------\n");
  printf("POKEDEX\n");
  printf("-----------------\n");
  for(int i=0;i<16;i++){
    printf("Number: %d\n", i+1);
    printf("Name: %s\n", dex[i].name);
    printf("Type: ");
    print_type(dex[i].type);
    printf("\n-----------------\n");
  }
}
Player zero_mon(Player new){
  // This function just turn all pokemon slots for "-1", to make easy to determinate the number of pokemon got (empty value)
  for(int i= 0; i<16;i++){
    new.pokemon_got[i] = -1;
  }
  // Each badge has a number, turning to -1 means empty
  for(int i=0;i<4;i++){
    new.badges[i] = -1;
  }
  return new;
}

void print_player_dex(Player new, Pokemon dex[]){
  // Calculing the number of badges
  int badges = 0;
  for(int i=0;i<4;i++){
    if(new.badges[i] != -1){
      badges +=1;
    }
  }
  // Printing the pokedex
  printf("\n\n\n\nPLAYER DEX:\n");
  printf("-----------------\n");
  printf("Badges: %d\n", badges);
  for(int i=0;new.pokemon_got[i]!=-1 ;i++){
    printf("-----------------\n");
    printf("Name: %s\n", dex[new.pokemon_got[i]].name);
    printf("Hp: %d\n", dex[new.pokemon_got[i]].hp);
    printf("Type: ");
    print_type(dex[new.pokemon_got[i]].type);
    printf("\n-----------------\n");
  }
}
Player mon_order_changer (Player new){
  //The first mon go to the last and the others i-1
  int save_zero = new.pokemon_got[0];
  int contador = 0;
  for(int i=1;new.pokemon_got[i]!=-1;i++){
    new.pokemon_got[i-1] = new.pokemon_got[i];
    contador++;
  }
  new.pokemon_got[contador] = save_zero;
  printf("Changing all your team position moving the first one to last position!\n");
  sleep(3);
  return new;
}