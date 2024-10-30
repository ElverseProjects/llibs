#ifndef ELLIPSE_2_MATH_H_
#define ELLIPSE_2_MATH_H_

/**************************************************************************//**
 * @file     math.h
 * @brief    Ellipse mathematic for C.
 * @version  V0.3.0
 * @date     22. Oct 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include "types.h"

/////////////////////////////////////////////
///////////// Types definition //////////////
/////////////////////////////////////////////

#include <float.h>
#include <math.h>


/////////////////////////////////////////////
/////////// Function declaration //////////// 
/////////////////////////////////////////////

extern imax_t abs(imax_t number);

extern fmax_t fabs(fmax_t number);

extern fmax_t fmax(fmax_t a, fmax_t b);
extern fmax_t fmin(fmax_t a, fmax_t b);
extern fmax_t fmean(fmax_t a, fmax_t b);

extern fmax_t flog(fmax_t number);
extern fmax_t fsqrt(fmax_t number);
extern fmax_t fpow(fmax_t number, fmax_t power);


#endif // ELLIPSE_2_MATH_H_