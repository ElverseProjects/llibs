#ifndef ELLIPSE_2_APPLICATION_H_
#define ELLIPSE_2_APPLICATION_H_

/**************************************************************************//**
 * @file     app.h
 * @brief    Ellipse application functions and utils for C.
 * @version  V0.3.0
 * @date     24. Oct 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <c/types.h>
#include <c/str.h>

/////////////////////////////////////////////
///////////// Type definitions ////////////// 
///////////////////////////////////////////// 

typedef i32_t main_t;
typedef struct {
    const i32_t num;
    cstr_t path;
    cstr_t* args;
} app_args_t;

typedef enum {
    ELLIPSE_INIT_EVERYTHING,
    ELLIPSE_INIT_CONOSOLE,
    ELLIPSE_INIT_AUTOLOGS,
    ELLIPSE_INIT_VIRTUAL_MEMORY,
    ELLIPSE_INII_MEMORY_PROTECT,
    ELLIPSE_INIT_HARDWARE_EXT_DEVICES,
    ELLIPSE_INIT_GPU,
} ellipse_init_flags_t;

typedef enum {
    EXIT_SUCCESS,
    EXIT_FAILURE,
} ellipse_exit_code_t;

/////////////////////////////////////////////
/////////// Function declaration //////////// 
///////////////////////////////////////////// 

// TODO DOCS!!
extern err_t terminal(cstr_t command);   
extern err_t ellipse_init(ellipse_init_flags_t flags);

extern void abort(ellipse_exit_code_t code);
extern void exit(ellipse_exit_code_t code);

extern main_t ellipse_main(app_args_t args);

#endif // ELLIPSE_2_APPLICATION_H_
