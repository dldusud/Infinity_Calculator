#include "PostCalculator.h"
#include "InfinityCalculator.h"

Num EvalRPNExp(List * postExp) {
    Operand operand;
    Num num, result;

    int flag = INT;
    int len[] = {0, 0};
    char tok;

    OperandInit(&operand);
    NumInit(&num);
    NumInit(&result);

    while (postExp->head != NULL) {
        tok = postExp->head->data;
        int n = tok - '0';

        if (isdigit(tok)) {
            if (flag == 0) {
                IntPartPush(&num, n);
                num.integer_part_size++;
            } else if (flag == FALSE){
                DecPartPush(&num, n);
                num.decimal_part_size++;
            }
        } else if (tok == '.') {
            flag = FALSE;
        } else if (tok == ' ') {
            flag = TRUE;
            OperandPush(&operand, &num);
        } else {
            switch (tok) {
                case '+':
                    result = Plus(OperandPop(&operand), OperandPop(&operand));
                case '-':
                    result = Minus(OperandPop(&operand), OperandPop(&operand));
                case '*':
                    result = Multiply(OperandPop(&operand), OperandPop(&operand));
                case '/':
                    result = Divide(OperandPop(&operand), OperandPop(&operand));
            }
        }
    }
    return result;
}

Num Plus(Num op1, Num op2) {
    int integer[] = { 0, };
    int decimal[] = { 0, };

    struct Digit *curr1 = (&op1)->decimal_part;
    struct Digit *curr2 = (&op2)->decimal_part;


    int i = 0;
    while (curr1->next != NULL || curr2->next != NULL) {
        decimal[i] = curr1->digit + curr2->digit;
        if (decimal[i] >= 10) {
            decimal[i] -= 10;
            decimal[i+1]++;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
}

Num Minus(Num op1, Num op2) {

}

Num Multiply(Num op1, Num op2) {

}

Num Divide(Num op1, Num op2) {

}

int main()
{
    List s;
    ListInit(&s);

    LInsert(1);
}
