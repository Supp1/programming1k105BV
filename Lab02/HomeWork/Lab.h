#ifndef LAB_H_INCLUDED
#define LAB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) -log(fabs(2 * sin(x / 2)))

#define CONDITION1(x) (x) <= -2
#define CONDITION2(x) (x) > -2 && (x) <= 2

#define FUNC1(x) (x) * (x) - 1
#define FUNC2(x) (x) * exp(-((x)*(x)))
#define FUNC3(x) (x) * (x) * (x) - (x) + 1

#endif // LAB_H_INCLUDED
