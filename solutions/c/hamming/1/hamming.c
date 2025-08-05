#include "hamming.h"

int compute(const char *lhs, const char *rhs){
    if (strlen(lhs) == strlen(rhs)){
        int count = 0;
        for(unsigned int i = 0; i < strlen(rhs); i++){
            if(lhs[i] != rhs[i]) count++;
        }
        return count;
    } 
    return -1;
}
