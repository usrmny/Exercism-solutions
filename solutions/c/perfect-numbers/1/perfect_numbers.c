#include "perfect_numbers.h"

kind classify_number(int num){
    if(num < 1) return -1;
    int total = 0;
    for(int i = 1; i < num / 2 + 1; i++){
        if(num % i == 0) total += i;
    }
    if(total == num) return 1;
    else if(total > num) return 2;
    else return 3;
}