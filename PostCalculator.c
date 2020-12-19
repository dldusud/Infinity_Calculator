#include "InfinityCalculator.h"
#include "PostCalculator.h"



Num EvalRPNExp(pList pos) {
    pOperand Operand;
    pDigit digit;
    pNum num;

    OperandInit(&Operand);
    ListInit(&digit);
    NumInit(&num);

    char tok, op1, op2;
    int flag = INT;
    int len[] = {0, 0};
    while (pos->head->next != pos->tail) {
        tok = pos->head->data;

        if(isdigit(tok)) {
            LInsert(&digit, tok);
            len[flag]++;
        }
        else if (tok == '.') {
            num->integer_part       = digit;
            num->integer_part_size  = len[flag];
            ListInit(&digit);
            flag = DEC;
        }
        else if (tok == ' ') {
            num->decimal_part       = digit;
            num->decimal_part_size  = len[flag];
            ListInit(&digit);
            flag = INT;

            Push(Operand, &num);
            NumInit(num);
        }
        else {
            pNum op1 = Pop(&Operand);
            pNum op2 = Pop(&Operand);
            switch (tok) {
                case '+':
                    Push(&Operand, Plus(op1, op2));
                    break;
                case '-':
                    Push(&Operand, Minus(op1, op2));
                    break;
                case '*':
                    Push(&Operand, Multiply(op1, op2));
                    break;
                case '/':
                    Push(&Operand, Divide(op1, op2));
                    break;
            }
        }
    }
    return Pop(&Operand);
}

Num Plus(pNum op1, pNum op2) {}

Num Minus(pNum op1, pNum op2) {}

Num Multiply(pNum op1, pNum op2) {}

Num Divide(pNum op1, pNum op2) {}

}