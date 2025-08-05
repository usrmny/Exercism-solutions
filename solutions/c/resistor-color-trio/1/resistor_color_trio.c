#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t* code){
    resistor_value_t result;
    result.value = (code[0] * 10 + code[1]);
    if(result.value == 0){
        result.unit = 0;
        return result;
    }

    for(resistor_band_t i = 0; i < code[2]; i++){
        result.value = result.value * 10;
    }

    if(result.value % 1000000000 == 0) {
        result.unit = GIGAOHMS;
        result.value /= 1000000000;  
    }
    else if(result.value % 1000000 == 0){
        result.unit = MEGAOHMS;
        result.value /= 1000000;  
    } 
    else if(result.value % 1000 == 0) {
        result.unit = KILOOHMS;
        result.value /= 1000;  
    }
    else result.unit = OHMS;
    
    return result;
}

/*
    while(result.value % 1000 == 0){
        result.value /= 1000;
        result.unit += 3;
        
    }
    */
    /*
    if(code[2] < 3) result.unit = OHMS;
    else if(code[2] < 6) result.unit = KILOOHMS;
    else if(code[2] < 9) result.unit = MEGAOHMS;
    else result.unit = GIGAOHMS;*/
