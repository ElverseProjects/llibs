#include <c/structures/stack.h>

#include <c/types.h>
#include <c/mem.h>


/////////////////////////////////////////////
//////////// Private functions ////////////// 
///////////////////////////////////////////// 


/////////////////////////////////////////////
///////////// Public functions ////////////// 
///////////////////////////////////////////// 

stack_t stack_create(void) {
    void* capacity = calloc_generic(STACK_INITIAL_ALLOCATION, 1);
    stack_t stack;
    stack.count = 0;
    stack.elements = (memory_t){
        .data = capacity,
        .allocated = STACK_INITIAL_ALLOCATION,
        .used = 0,
    };
    return stack;
}

void stack_destroy(stack_t* stack) {
    stack->count = 0;
    freeing(stack->elements);
}

void stack_push(stack_t* stack, stack_element_t element) {
    stack_element_t* buffer = (stack_element_t *)(stack->elements.data);
    switch (element.type) {
    case TYPE_I8:
        buffer[stack->count + 1].value.i8   = element.value.i8;
        buffer[stack->count + 1].type       = element.type;
        break;
    case TYPE_U8:
        buffer[stack->count + 1].value.u8   = element.value.u8;
        buffer[stack->count + 1].type       = element.type;
        break;

    case TYPE_I16:
        buffer[stack->count + 1].value.i16  = element.value.i16;
        buffer[stack->count + 1].type       = element.type;
        break;
    case TYPE_U16:
        buffer[stack->count + 1].value.u16  = element.value.u16;
        buffer[stack->count + 1].type       = element.type;
        break;

    case TYPE_I32:
        buffer[stack->count + 1].value.i32  = element.value.i32;
        buffer[stack->count + 1].type       = element.type;
        break;
    case TYPE_U32:
        buffer[stack->count + 1].value.u32  = element.value.u32;
        buffer[stack->count + 1].type       = element.type;
        break;

    case TYPE_I64:
        buffer[stack->count + 1].value.i64  = element.value.i64;
        buffer[stack->count + 1].type       = element.type;
        break;
    case TYPE_U64:
        buffer[stack->count + 1].value.u64  = element.value.u64;
        buffer[stack->count + 1].type       = element.type;
        break;

    case TYPE_IMAX:
        buffer[stack->count + 1].value.imax = element.value.imax;
        buffer[stack->count + 1].type       = element.type;
        break;
    case TYPE_UMAX:
        buffer[stack->count + 1].value.umax = element.value.umax;
        buffer[stack->count + 1].type       = element.type;
        break;
    case TYPE_FMAX:
        buffer[stack->count + 1].value.fmax = element.value.fmax;
        buffer[stack->count + 1].type       = element.type;
        break;
#ifdef __SIZEOF_INT128__
    case TYPE_I128:
        buffer[stack->count + 1].value.i128  = element.value.i128;
        buffer[stack->count + 1].type       = element.type;
        break;
    case TYPE_U128:
        buffer[stack->count + 1].value.u128  = element.value.u128;
        buffer[stack->count + 1].type       = element.type;
        break;
#endif
#ifdef __SIZEOF_FLOAT128__
    case TYPE_F128:
        buffer[stack->count + 1].value.f128  = element.value.f128;
        buffer[stack->count + 1].type       = element.type;
        break;
#endif
    default:
        // GET OUT!!!!!!!!
    } 
}


stack_element_t stack_pop(stack_t* stack);

bool stack_is_empty(stack_t stack);


void stack_strip(stack_t* stack) {

}

void stack_expand(stack_t* stack) {

}


size_t stack_get_size(stack_t stack);


size_t stack_get_count(stack_t stack);

