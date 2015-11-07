#ifndef __MATHS__
#define __MATHS__
#include <stdlib.h>

inline double
max(double x0, double x1);

inline double
max(double x0, double x1)
{
	return((x0 > x1) ? x0 : x1);
}
inline float rand_float()
{
    return rand() / (RAND_MAX + 1.);
}
#endif
