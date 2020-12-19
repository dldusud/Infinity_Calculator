#ifndef __POST_CALCULATOR_H__
#define __POST_CALCULATOR_H__

#define INT     0
#define DEC     1

Num EvalRPNExp(pList list);
Num Plus(pNum op1, pNum op2);
Num Minus(pNum op1, pNum op2);
Num Multiply(pNum op1, pNum op2);
Num Divide(pNum op1, pNum op2);

#endif