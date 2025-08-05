#include "resistor_color_duo.h"


uint16_t color_code(resistor_band_t* code){
    return code[0] * 10 + code[1];
}