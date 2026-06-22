#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

typedef struct {
    Shape base;
    int radius;
} Circle;

DECLARE_TYPE_INFO(Circle);

void Circle_Init(Circle* self, int x, int y, int radius);

#endif
