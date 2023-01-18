#include <screen.h>

/*
The first pokemon for the player is dex[0] bulbasaur Grass type.

There's 3 types of pokemon
type 1 basic: 2 dmg, 10hp
type 2 gym: 3 dmg, 20 hp
type 3 final_gym: 4 dmg, 30hp

The player can only have a type 1 pokemon
*/

Player heal_poke (Player new, Pokemon dex[]){
  
// This function act like a PokeCenter, turning your team to full hp (10)
  for(int i=0; new.pokemon_got[i]!=-1;i++){
    dex[new.pokemon_got[i]].hp = 10;
  }
  return new;
}
int advantages (Pokemon dex[], int a, int b){
  // The 'a' pokemon is attackant and the 'b' is the defenser
  // Only using Fire(0), Grass(1), Ground(2), Eletric(3), Water(4) and Ghost(5)
  // IMPORTANT! -> Not considering the desavanteges in the attack math.
  
  int damage = 1; // multiplier
  
  // The supper effective attacks
  if(dex[a].type == 0 && dex[b].type == 1){ 
    damage = 2;
    // Fire > Grass
  }else if(dex[a].type == 1 && (dex[b].type == 2 || dex[b].type == 4)){
    damage = 2;
    // Grass > (Ground or Water)
  }else if(dex[a].type == 3 && dex[b].type == 4){
    damage = 2;
    // Eelectric > Water
  }else if(dex[a].type == 4 && dex[b].type == 0){
    damage = 2;
    // Water > Fire
  }
  return damage;
}
void print_battle(Pokemon dex[], int a, int b){
  // 'a' is the attacking mon and 'b' the defender
  // This function prints the HP
  printf("\n----------------\n");
  printf("%s has %d HP\n", dex[a].name, dex[a].hp);
  printf("%s has %d HP\n", dex[b].name, dex[b].hp);
  printf("----------------\n\n");
  }
Player battle (Player new, Pokemon dex[], int opponent, Local map[H][L]){
  /*
  Check pokemon with hp in order, if has hp, battle
  Check the opponents hp
  Check the advantages, if has, 2x dmg
  */
  bool defeated = false; // Used to badges and capture features
  int player_mon = 0; // Used to set the player dex attack order

  while(defeated !=true){

    // Check if already won
    if(dex[opponent].hp <1){
      defeated = true;
      printf("\n\n\n%s defeated %s!!!\n\n\n", dex[new.pokemon_got[player_mon]].name, dex[opponent].name);
      break;
    }
    // Check if the player has more pokemon avaliable
    if(new.pokemon_got[player_mon] == -1){
      printf("YOU LOST THE BATTLE\n");
      break;
    }
    // Check if the players mon has gone;
    if(dex[new.pokemon_got[player_mon]].hp <1){
      player_mon++; // If true, go to the next
    }
    // Print the hp
    print_battle(dex, new.pokemon_got[player_mon], opponent);
    sleep(2);
    // Check the advantage for player 1;
    int damage = advantages(dex, new.pokemon_got[player_mon], opponent);
    printf("%s is attacking %s\n", dex[new.pokemon_got[player_mon]].name, dex[opponent].name);
    sleep(2);
    if(damage == 2){
      // If has advantage -> s.e. attack
      printf("\nThe attack was super effective!\n");
      sleep(2);
    }
    // Removing the hp from opponent
    dex[opponent].hp -= damage * dex[new.pokemon_got[player_mon]].damage;
    sleep(2);
    // Validate the "less than 0 hp"
    if(dex[opponent].hp <0){
      dex[opponent].hp = 0;
    }
    print_battle(dex, new.pokemon_got[player_mon], opponent);
    sleep(2);
    // Check if opponent was defeated
    if(dex[opponent].hp <1){
      printf("\n\n\n%s defeated %s!!!\n\n\n", dex[new.pokemon_got[player_mon]].name, dex[opponent].name);
      defeated = true;
      break;
    }
    // Opponents turn
    printf("%s is attacking %s\n", dex[opponent].name, dex[new.pokemon_got[player_mon]].name);
    sleep(2);
    // Checking the advantages
    damage = advantages(dex, opponent, new.pokemon_got[player_mon]);
    if(damage == 2){
      printf("The attack was super effective!\n");
    }
    sleep(2);
    // Removing the hp
    dex[new.pokemon_got[player_mon]].hp -= damage * dex[opponent].damage;
    // Validing the "lass than 0 hp"
    if(dex[new.pokemon_got[player_mon]].hp < 0){
      dex[new.pokemon_got[player_mon]].hp = 0;
    }
    // Check: the players mon is alive and the next is valid
    if(dex[new.pokemon_got[player_mon]].hp <1){
      printf("Your %s has gone!\n", dex[new.pokemon_got[player_mon]].name);
      player_mon++;
    }
    // Valid
    if(new.pokemon_got[player_mon] == -1){
      printf("YOU LOST THE BATTLE\n");
      break;
    }
  }
  // If the player lost the battle:
  if(defeated == false){
    // Back to the main city and heal team
    printf("All pokemon GONE -> backing to ICE\n");
    printf("healing...");
    heal_poke(new, dex);
    sleep(5);
    // Ajusting the map
    map[new.last_coord[0]][new.last_coord[1]].symbol = '+';
    new.last_coord[0] = 3;
    new.last_coord[1] = 2;  
    map[new.last_coord[0]][new.last_coord[1]].symbol = 'X';
  }
  // If the player won the battle:
  if(defeated == true){
    new.last_battle = true;
  }
  // Extra Verify if one pokemon has <0 hp
  if(dex[new.pokemon_got[player_mon]].hp <0){
    dex[new.pokemon_got[player_mon]].hp = 0;
  }
  if(dex[opponent].hp <0){
    dex[opponent].hp = 0;
  }
  return new;
}