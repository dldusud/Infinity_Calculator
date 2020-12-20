#ifndef __POST_CALCULATOR_H__
#define __POST_CALCULATOR_H__

#include "InfixToPostfix.h"

#define INT     0;
#define DEC     1;

Num EvalRPNExp(pList * postExp);

Plus(Num op1, Num op2);

Minus(Num op1, Num op2);

Multiply(Num op1, Num op2);

Divide(Num op1, Num op2);

#endif