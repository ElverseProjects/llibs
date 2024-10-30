#ifndef ELLIPSE_2_STRUCTURES_DYNAMIC_QUEUE_H_
#define ELLIPSE_2_STRUCTURES_DYNAMIC_QUEUE_H_

/**************************************************************************//**
 * @file     stack.h
 * @brief    Ellipse advanced / stack for C.
 * @version  V0.3.0
 * @date     22. Oct 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <c/types.h>
#include <c/mem.h>

/////////////////////////////////////////////
////////////// Type definition ////////////// 
///////////////////////////////////////////// 

typedef any_t queue_value_t;

typedef struct {
    queue_value_t value;
    type_t type;
} queue_element_t;

typedef struct {
    memory_t data;
    struct {
        ptr_t ptr;
        type_t type;
    } head;
    struct {
        ptr_t ptr;
        type_t type;
    } tail;
    len_t count;
} queue_t;

#ifndef DYNAMIC_TYPE_STACK_INITIAL_ALLOCATION_N
#   define DYNAMIC_TYPE_STACK_INITIAL_ALLOCATION_N 128
#   define DYNAMIC_TYPE_STACK_INITIAL_ALLOCATION (size_t)\
    (DYNAMIC_TYPE_STACK_INITIAL_ALLOCATION_N * sizeof(stack_element_t))
#endif

/////////////////////////////////////////////
/////////// Function declaration //////////// 
///////////////////////////////////////////// 


extern queue_t queue_create(void);

extern queue_t queue_push(queue_t* queue, queue_element_t element);
extern queue_element_t queue_pop(queue_t* queue, queue_element_t element);
extern status_t queue_strip(queue_t* queue);
extern status_t queue_expand(queue_t* queue);
extern bool queue_is_empty(queue_t* queue);
extern size_t queue_get_size(queue_t* queue);
extern len_t queue_get_count(queue_t* queue);

#endif // ELLIPSE_2_STRUCTURES_DYNAMIC_STACK_H_