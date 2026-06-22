#include <stdio.h>
#include "shape.h"
#include "circle.h"

int main() {
    printf("=== C语言实现C++类封装演示 ===\n\n");

    printf("[1] 测试基类 (Shape):\n");
    Shape s;
    Shape_Init(&s, 10, 20);
    Shape_Draw(&s);
    printf("面积: %.2f\n", Shape_Area(&s));
    Shape_PrintTypeInfo(&s);
    printf("\n");

    printf("[2] 测试派生类 (Circle):\n");
    Circle c;
    Circle_Init(&c, 5, 5, 10);
    Shape* poly_s = (Shape*)&c;
    printf("通过 Shape* 调用方法 (多态性检查):\n");
    Shape_Draw(poly_s);
    printf("面积: %.2f (预期值 ~314.16)\n", Shape_Area(poly_s));
    printf("\n");

    printf("[3] 动态类型反查 (基类指针 -> 实际类型):\n");
    printf("通过 Shape* 指针反查实际对象类型:\n");
    Shape_PrintTypeInfo(poly_s);
    printf("\n");

    printf("[4] 类型名直接访问:\n");
    printf("poly_s 指向对象的类型名: %s\n", TypeInfo_Name(poly_s->type_info));
    printf("poly_s 指向对象的父类型名: %s\n", TypeInfo_ParentName(poly_s->type_info));
    printf("poly_s 指向对象的大小: %zu 字节\n", TypeInfo_Size(poly_s->type_info));
    printf("纯 Shape 对象的类型名: %s\n", TypeInfo_Name(s.type_info));
    printf("纯 Shape 对象的父类型名: %s\n", TypeInfo_ParentName(s.type_info));

    return 0;
}
