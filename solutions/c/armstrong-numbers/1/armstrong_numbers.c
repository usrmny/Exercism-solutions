#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate){
    if(candidate < 0) return false;
    int temp = candidate;
    int total = 0, count = 1, findLen = 1;
    while(findLen < candidate){
        findLen *= 10;
        count++;
    }
    count--;
    for(int i = 0; i < count; i++){
        total += pow((temp % 10), count);
        temp /= 10;
        //printf("%d\n", total);
    }
    return total == candidate;
}
