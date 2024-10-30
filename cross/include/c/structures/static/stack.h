#ifndef ELLIPSE_2_STRUCTURES_STATIC_STACK_H_
#define ELLIPSE_2_STRUCTURES_STATIC_STACK_H_

/**************************************************************************//**
 * @file     stack.h
 * @brief    Ellipse advanced / dynamic typed stack for C.
 * @version  V0.3.0
 * @date     22. Oct 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <c/types.h>
#include <c/mem.h>

/////////////////////////////////////////////
////////////// Type definition ////////////// 
///////////////////////////////////////////// 

typedef struct {
    memory_t data;
    size_t size_of_type;
} s_stack_t;

#ifndef STATIC_TYPE_STACK_INITIAL_ALLOCATION_N
#   define STATIC_TYPE_STACK_INITIAL_ALLOCATION_N 4096UL
#endif

/////////////////////////////////////////////
/////////// Function declaration //////////// 
/////////////////////////////////////////////

extern s_stack_t s_stack_create(type_t type_of_element);
extern s_stack_t s_stack_create_sizeof(size_t size_of_element);

extern 

#endif // ELLIPSE_2_STRUCTURES_STATIC_STACK_H_