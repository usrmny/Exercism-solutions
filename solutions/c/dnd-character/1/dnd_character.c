#include "dnd_character.h"

int ability(void){
    int total = 0;
    int lowest = 11;
    int value;
    for(int i = 0; i < 4; i++){
        value = rand() % 6 + 1;
        total += value;
        if(lowest > value) lowest = value;
    }
    return total - lowest;
}

int modifier(int score){
    int hp = (score - 10);
    return hp < 0 && hp & 1 ? hp/2 - 1 : hp/2;
}

dnd_character_t make_dnd_character(void){
    dnd_character_t cha;
    cha.strength = ability();
    cha.dexterity = ability();
    cha.constitution = ability();
    cha.intelligence = ability();
    cha.wisdom = ability();
    cha.charisma = ability();
    cha.hitpoints = 10 + modifier(cha.constitution);
    return cha;
}
