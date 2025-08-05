#include "binary.h"

int convert(const char *input){
    int len = (int) strlen(input);
    if(!len) return -1;
    int total = 0;
    for(int i = len - 1, k = 0; i >= 0; i--, k++){
        if(input[i] != '0' && input[i] != '1') return -1;
        total += ((int) input[i] - '0') * pow(2, k);
    }
    return total;
}
//"10100"