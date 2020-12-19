#include <stdio.h>
#include "LinkedList.h"
#include "Stack.h"
#include "InfinityCalculator.h"

int main(void) {

    char* exp;
    Num result;
    List postfix_Expr;

    postfix_Expr = inf_to_pos(exp);
    result = calculator(&postfix_Expr);
    print_result(result);


}

