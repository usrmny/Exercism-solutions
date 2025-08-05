#ifndef DARTS_H
#define DARTS_H
#include <math.h>
#include <stdbool.h>

typedef struct{
    float x;
    float y;
}coordinate_t;

int score(coordinate_t pos);
float pythagore(float x, float y);
bool legal(coordinate_t pos);

#endif
