#ifndef ELLIPSE_2_UTILS_HANDLERS_H_
#define ELLIPSE_2_UTILS_HANDLERS_H_

/**************************************************************************//**
 * @file     handlers.h
 * @brief    Ellipse error handlers.
 * @version  V0.3.0
 * @date     24. Oct 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <c/types.h>
#include <c/str.h>
#include <c/logs.h>

/////////////////////////////////////////////
//////////// Function declaration /////////// 
///////////////////////////////////////////// 

/**
 * 
 */
extern void error_handler_set(err_t error, void*(handler)(void), file_point_t point);

/**
 * 
 */
extern void error_handler_call(err_t error, file_point_t point);

#endif // ELLIPSE_2_UTILS_HANDLERS_H_