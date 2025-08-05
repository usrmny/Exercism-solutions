#include "collatz_conjecture.h"

/*int steps(int start){
    static int count = 0;
    if(start < 1) return ERROR_VALUE;
    if(start == 1) return count;
    count++;
    return (start % 2 == 0) ? steps(start/2) : steps(start * 3 + 1);
}
*/
int steps(int start){
    if(start < 1) return ERROR_VALUE;
    int counte = 0;
    while(start > 1){
        if(start % 2 == 0){
            start /= 2;
        }
        else {
            start = start * 3 + 1;
        }
        counte++;
    }
    return counte;
}