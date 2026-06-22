#ifndef SHAPE_H
#define SHAPE_H

#include "type_info.h"

typedef struct Shape Shape;

#define SHAPE_DRAW 0
#define SHAPE_AREA 1
#define SHAPE_VTABLE_SIZE 2

typedef void (*Shape_Draw_Fn)(Shape*);
typedef double (*Shape_Area_Fn)(Shape*);

struct Shape {
    const TypeInfo* type_info;
    int x;
    int y;
    void (*vtable[SHAPE_VTABLE_SIZE])(void*);
};

DECLARE_TYPE_INFO(Shape);

void Shape_Init(Shape* self, int x, int y);

void Shape_Draw(Shape* self);
double Shape_Area(Shape* self);
void Shape_PrintTypeInfo(Shape* self);

#endif
