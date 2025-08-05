#ifndef DARTS_H
#define DARTS_H
#include <math.h>

typedef struct{
    float x;
    float y;
}coordinate_t;

int score(coordinate_t pos);
float pythagore(float x, float y);

#endif
