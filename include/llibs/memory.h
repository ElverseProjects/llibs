#ifndef LMEMORY_H_
#define LMEMORY_H_

#include <stdlib.h>
#include "types.h"
#include "errors.h"

extern void* lalloc(llen num, lsize size_of_element);
extern lerr lrealloc(void** ptr, llen num, lsize size_of_element);
extern void lfree(void* ptr);
extern llen lmem_allocated(void);


#define LREALLOC(ptr, num, size) lrealloc((void**)&(ptr), (num), (size))

#endif // LMEMORY_H_
