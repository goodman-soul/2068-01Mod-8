#ifndef TYPE_INFO_H
#define TYPE_INFO_H

#include <stddef.h>
#include <stdio.h>

typedef struct TypeInfo TypeInfo;

struct TypeInfo {
    const char* name;
    const TypeInfo* parent;
    size_t size;
};

#define DECLARE_TYPE_INFO(TypeName) \
    extern const TypeInfo TypeName##_TypeInfo

#define DEFINE_TYPE_INFO(TypeName, ParentName, TypeSize) \
    const TypeInfo TypeName##_TypeInfo = { \
        .name = #TypeName, \
        .parent = ParentName, \
        .size = TypeSize \
    }

static inline const char* TypeInfo_Name(const TypeInfo* info) {
    return info ? info->name : "unknown";
}

static inline const char* TypeInfo_ParentName(const TypeInfo* info) {
    return (info && info->parent) ? info->parent->name : "none";
}

static inline size_t TypeInfo_Size(const TypeInfo* info) {
    return info ? info->size : 0;
}

static inline void TypeInfo_Print(const TypeInfo* info) {
    if (!info) {
        printf("TypeInfo: <null>\n");
        return;
    }
    printf("TypeInfo: name=%s, parent=%s, size=%zu\n",
           info->name,
           info->parent ? info->parent->name : "none",
           info->size);
}

#endif
