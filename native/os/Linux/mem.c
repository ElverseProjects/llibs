#include <c/mem.h>
#include <c/app.h>
#define _GNU_SOURCE
#include <sys/mman.h>

/////////////////////////////////////////////
///////// Static / Private functions //////// 
///////////////////////////////////////////// 


static const int __prot_map[] = {
    [MEMORY_ACCESS_DENIED]      = PROT_NONE,
    [MEMORY_ACCESS_READ]        = PROT_READ,
    [MEMORY_ACCESS_WRITE]       = PROT_WRITE,
    [MEMORY_ACCESS_FULL]        = PROT_READ | PROT_WRITE,
    [MEMORY_ACCESS_GROWSDOWN]   = PROT_GROWSDOWN,
    [MEMORY_ACCESS_GROWSUP]     = PROT_GROWSUP
};

/////////////////////////////////////////////
//////// Memory allocation functions //////// 
///////////////////////////////////////////// 

memory_t allocate(len_t num, size_t sizeof_element) {
    size_t allocated = num * sizeof_element;
    memory_t data = (memory_t){
        .access = MEMORY_ACCESS_FULL,
        .data = mmap(NULL, 
            allocated, 
            PROT_READ | PROT_WRITE,
            MAP_PRIVATE | MAP_ANONYMOUS,
            -1,
            0
        ),
        .used = 0,
        .allocated = allocated
    };
    if (data.data == MAP_FAILED) {
        // --------------- TODO: Error handler
        mem_global_all_resources_free();
        abort(EXIT_FAILURE);
    }
    return data;
}

void freeing(memory_t* memory) {
    if (munmap(memory->data, memory->allocated) == -1) {
        // --------------- TODO: Error handler
        abort(EXIT_FAILURE);
    }
    memory->access    = MEMORY_ACCESS_DENIED;
    memory->data      = MEMORY_NO_DATA;
    memory->allocated = 0;
    memory->used      = 0;
}

memory_t reallocate(memory_t* memory, len_t num, size_t sizeof_element) {
    if (memory == NULL) {
        // --------------- TODO: Error handler
    }
    size_t allocated = num * sizeof_element;
    memory_t data = (*memory);
    
    if (allocated > memory->allocated) {
        data.allocated = allocated;
        data.data = mremap(
            memory->data, 
            memory->allocated,
            allocated,
            MREMAP_MAYMOVE
        );
    }

    if (data.data == MAP_FAILED) {
        // --------------- TODO: Error handler
        mem_global_all_resources_free();
        abort(EXIT_FAILURE);
    }

    return data;
}


memory_t reallocate_force(memory_t* memory, len_t num, size_t sizeof_element) {
    if (memory == NULL) {
        // --------------- TODO: Error handler
    }

    size_t allocated = num * sizeof_element;
    memory_t data = (*memory);
    
    data.allocated = allocated;
    data.data = mremap(
        memory->data, 
        memory->allocated,
        allocated,
        MREMAP_MAYMOVE
    );

    if (data.data == MAP_FAILED) {
        // --------------- TODO: Error handler
        mem_global_all_resources_free();
        abort(EXIT_FAILURE);
    }

    if (data.used > allocated)
        data.used = allocated;

    return data;
}


err_t mem_access(memory_t* memory, memory_access_t level) {
    if (memory == NULL) {
        // --------------- TODO: Error handler
    }
    if (mprotect(memory->data, memory->allocated, __prot_map[level]) == -1) {
        return ERR_MEM_GENERAL;
    }
    return ERR_OK;
}

err_t mem_strip(memory_t* memory) {
    if (memory == NULL) {
        // --------------- TODO: Error handler
    }

    if (memory->used == 0) {
        if (munmap(memory->data, memory->allocated) == -1) {
            // --------------- TODO: Error handler
            abort(EXIT_FAILURE);
        }
        memory->access    = MEMORY_ACCESS_DENIED;
        memory->data      = MEMORY_NO_DATA;
        memory->allocated = 0;
        memory->used      = 0;
        
    } else if (memory->allocated > memory->used) {

        memory->data = mremap(
            memory->data, 
            memory->allocated,
            memory->used,
            MREMAP_MAYMOVE
        );

        if (memory->data == MAP_FAILED) {
            // --------------- TODO: Error handler
            mem_global_all_resources_free();
            abort(EXIT_FAILURE);
        }

    }
    return ERR_OK;
}
