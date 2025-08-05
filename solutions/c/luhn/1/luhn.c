#include "luhn.h"

bool luhn(const char *num){
    int len = strlen(num); 
    if(len < 2) return false;

    int temp[50];
    int i = 0;
    int count = 0;
    while(num[i] != '\0'){
        if(!(isspace(num[i]))) {
            if(!isdigit(num[i])) return false;
            temp[count++] = num[i] - '0';   
        }
        i++;
    }
    if(count < 2) return false;

    for(int j = count - 2; j >= 0; j -= 2){
        int di = 2* (temp[j]);
        temp[j] = (di > 9) ? di - 9 : di;
    }

    int sum = 0;
    for(int k = 0; k < count; k++){
        sum += temp[k];
        printf("%d - %d\n", sum, temp[k]);
    }
    return sum % 10 == 0; 
}