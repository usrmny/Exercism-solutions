#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number){
    if(number == 0) return 0;
    return sum_of_squares(number - 1) + (number * number);
}
unsigned int square_of_sum(unsigned int number){
    int count = 0;
    for(unsigned int i = 0; i <= number; i++){
        count += i;
    }
    return count * count;
}
unsigned int difference_of_squares(unsigned int number){
   
    return square_of_sum(number) - sum_of_squares(number);
}