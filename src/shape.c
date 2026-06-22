#include "shape.h"
#include <stdio.h>

DEFINE_TYPE_INFO(Shape, NULL, sizeof(Shape));

static void default_draw_impl(void* self_ptr) {
    Shape* self = (Shape*)self_ptr;
    printf("Shape[基类] 位于 (%d, %d)\n", self->x, self->y);
}

static double default_area_impl(Shape* self) {
    return 0.0;
}

void Shape_Init(Shape* self, int x, int y) {
    self->type_info = &Shape_TypeInfo;
    self->x = x;
    self->y = y;
    self->vtable[SHAPE_DRAW] = default_draw_impl;
    self->vtable[SHAPE_AREA] = (void (*)(void*))default_area_impl;
}

void Shape_Draw(Shape* self) {
    Shape_Draw_Fn fn = (Shape_Draw_Fn)self->vtable[SHAPE_DRAW];
    fn(self);
}

double Shape_Area(Shape* self) {
    Shape_Area_Fn fn = (Shape_Area_Fn)self->vtable[SHAPE_AREA];
    return fn(self);
}

void Shape_PrintTypeInfo(Shape* self) {
    if (!self || !self->type_info) {
        printf("类型信息: <未知>\n");
        return;
    }
    const TypeInfo* info = self->type_info;
    printf("实际类型: %s\n", info->name);
    printf("父类型:   %s\n", info->parent ? info->parent->name : "none");
    printf("对象大小: %zu 字节\n", info->size);
    if (info->parent) {
        printf("继承链:   ");
        const TypeInfo* cur = info;
        while (cur) {
            printf("%s", cur->name);
            cur = cur->parent;
            if (cur) printf(" -> ");
        }
        printf("\n");
    }
}
