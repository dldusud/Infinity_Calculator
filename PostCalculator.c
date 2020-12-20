#include "PostCalculator.h"
#include "InfinityCalculator.h"

Num EvalRPNExp(List * postExp) {
    Operator operator;
    Operand operand;
    List list;
    Digit digit;
    Num result;

    int flag = INT;
    int len[] = {0, 0};
    char tok, op1, op2;

    OperatorInit(&operator);
    OperandInit(&operand);
    ListInit(&list);

    while (list->head->next != NULL) {
        tok = postExp->head;

        if (isdigit(tok)) {
            OperandPush(&list, )

        }
    }

}

Plus(Num op1, Num op2)

Minus(Num op1, Num op2)

Multiply(Num op1, Num op2)

Divide(Num op1, Num op2)
