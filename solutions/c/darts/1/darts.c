#include "darts.h"

bool legal(coordinate_t pos){
    return (pythagore(pos.x, pos.y) );
}

float pythagore(float x, float y){
    return sqrt(x * x + y * y);
}

int score(coordinate_t pos){
    float coor = pythagore(pos.x, pos.y);
    if(coor <= 1) return 10;
    if(coor <= 5) return 5;
    if(coor <= 10) return 1;
    return 0;
    
}