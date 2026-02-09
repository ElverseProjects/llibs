#ifndef DYN_TYPES_H_
#define DYN_TYPES_H_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "types.h"
#include "memory.h"

typedef struct {
    llen length;
    lsize size_of_elem;
    void * data;
} ld;

ld ld_create(llen length, lsize size_of_elem) {
    if (!size_of_elem || !length) return (ld){0, 0, NULL};

    ld buffer = {
        .length = length,
        .size_of_elem = size_of_elem,
        .data = lalloc(length, size_of_elem),
    };

    if (buffer.data == NULL) return (ld){0, 0, NULL};
    return buffer;
}


void ld_destroy(ld* buffer) {
    if (!buffer) return;
    free(buffer->data);
    buffer->length = 0;
    buffer->size_of_elem = 0;
}

void* ld_extract(ld buffer, llen index) {
    if (!(buffer.data && buffer.length && buffer.size_of_elem))
        return NULL;

    if (index >= buffer.length)
        return NULL;

    return (char*)buffer.data + index * buffer.size_of_elem;
}

void ld_edit(ld buffer, llen index, void* new_data) {
    if (!(buffer.data && buffer.length && buffer.size_of_elem && index && new_data))
        return;

    void* dest = (lu8*)buffer.data + index * buffer.size_of_elem;
        
    switch (buffer.size_of_elem) {
    case 1UL:
        *((lu8*)dest + index) = *(lu8*)new_data;
        break;
    case 2UL:
        *((lu16*)dest + index) = *(lu16*)new_data;
        break;
    case 4UL:
        *((lu32*)dest + index) = *(lu32*)new_data;
        break;
    case 8UL:
        *((lu64*)dest + index) = *(lu64*)new_data;
        break;
    default:
        // memcpy()

    }
}

#endif // DYN_TYPES_H_
