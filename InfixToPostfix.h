##ifndef __INFIX_TO_POSTFIX_H__
##define __INFIX_TO_POSTFIX_H__

##include "InfinityCalculator.h"

#define TRUE        1
#define FALSE       0

int getOpPrec(char op);
int whoPrecOp(char op1, char op2);
pList EvalRPNExp(char * exp);

##endif