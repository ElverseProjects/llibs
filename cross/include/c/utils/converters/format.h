#ifndef ELLIPSE_2_FORMAT_H_
#define ELLIPSE_2_FORMAT_H_

/**************************************************************************//**
 * @file     format.h
 * @brief    Ellipse advanced / dynamic typed stack for C.
 * @version  V0.3.0
 * @date     22. Oct 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <c/types.h>
#include <c/str.h>

/////////////////////////////////////////////
/////////// Function declaration //////////// 
/////////////////////////////////////////////

extern str_t* format(cstr_t format, ...);
extern xstr_t* xformat(xstr_t format, ...);

#endif // ELLIPSE_2_FORMAT_H_