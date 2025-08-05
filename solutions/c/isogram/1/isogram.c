#include "isogram.h"

bool is_isogram(const char phrase[]){
    int i = 0;
    int count = 0;
    if(phrase == NULL) return false;
    while(phrase[i] != '\0'){
        char letter = tolower(phrase[i]);
        if(letter >= 'a' && letter <= 'z'){
            int index = letter - 'a';
            if(((count >> index) & 1) == 0){
                count |= 1 << index;
            }
            else return false;
        }
        i++;
    }
    
    return true;
}
