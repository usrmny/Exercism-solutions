#include "eliuds_eggs.h"

/*
int egg_count(int dec){
    if( dec == 0) return 0;
    
    int power = 1;
    int temp = dec;
    int count = 0;
    int num = 0;
    
    while(dec >= power){
        power = power << 1;
        num++;
    }
    power = power >> 1;;
    char* eggs = malloc((num + 1) * sizeof(char));
    if(!eggs) return -1;

    //int max = power;
    while(num > 0){
        if(temp >= power){
            temp -= power;
            eggs[num - 1] = '1';
            count++;
        }
        else{
          eggs[num - 1] = '0';  
        }
        num--;
        power = power >> 1;
    }
    free(eggs);
    return count;
    
}
MISUNDERSTOOD THE ASSIGNMENT!!! */

int egg_count(int dec){
    int temp = dec;
    int count = 0;
    while(temp != 0){
        if(temp & 1) count++;
        temp = temp >> 1;
    }
    return count;
}