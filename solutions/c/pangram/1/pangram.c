#include "pangram.h"

bool is_pangram(const char *sentence){
    if(sentence == NULL) return false;
    int i = 0;
    int count = 0;
    char letters[26];
    bool hasLetter;
    while(sentence[i] != '\0'){
        char letter = tolower(sentence[i]);
        if(letter >= 'a' && letter <= 'z'){
            hasLetter = false;
            for(int j = 0; j < count; j++){
                if(letters[j] == letter) {
                    hasLetter = true;
                    break;
                }
            }
            if(!hasLetter) letters[count++] = letter;
            if(count == 26) return true;
        }

        
        i++;
    }
    return false;
}


