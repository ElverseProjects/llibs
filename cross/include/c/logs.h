#ifndef ELLIPSE_2_LOGS_H_
#define ELLIPSE_2_LOGS_H_

/**************************************************************************//**
 * @file     logs.h
 * @brief    Ellipse asserts for C.
 * @version  V0.3.0
 * @date     30. Sep 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <c/types.h>
#include <c/str.h>

/////////////////////////////////////////////
///////////// Type definitions ////////////// 
///////////////////////////////////////////// 

typedef enum {
    LOG_LEVEL_DISABLE,
    LOG_LEVEL_1,
    LOG_LEVEL_2,
    LOG_LEVEL_3,
    LOG_LEVEL_ALL,
} log_level_t;

typedef struct {
    len_t line;
    len_t indent;
    cstr_t filename;
    cstr_t funcname;
} file_point_t;

/////////////////////////////////////////////
//////////// Macros definition ////////////// 
///////////////////////////////////////////// 


/////////////////////////////////////////////
/////////// Function declaration //////////// 
///////////////////////////////////////////// 

/**
 * `filename:line:indent:` in function `funcname`
 */
void file_point_print(file_point_t point);
void log_info(log_level_t level, cstr_t message);

#endif // ELLIPSE_2_LOGS_H_
