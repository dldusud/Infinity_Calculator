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
            OperandPush(&operand, num);
        } else {
            switch (tok) {
                Num op2 = OperandPop(&operand);
                Num op1 = OperandPop(&operand);
                case '+':
                    result = Plus(&op1, &op2);
                case '-':
                    result = Minus(&op1, &op2);
                case '*':
                    result = Multiply(&op1, &op2);
                case '/':
                    result = Divide(OperandPop(&operand), OperandPop(&operand));
            }
        }
    }
    return result;
}

Num Plus(Num *op1, Num *op2) {
    Num result;     // 계산 결과 저장 구조체

    NumInit(&result);

    // 정수 부분, 소수 부분의 차이, tok = TRUE면 정수 첫 번재 자리에서 +1
    int decimal_gap = op1->decimal_part_size - op2->decimal_part_size;
    int integer_gap = op1->integer_part_size - op2->integer_part_size;
    int tok = FALSE;

    if (decimal_gap > 0) {
        // 소수 부분 길이의 차이만큼 긴 소수의 숫자 Push
        for (int i = 0; i < decimal_gap; ++i) {
            DecPartPush(&result, op1->decimal_part->digit);
            op1->decimal_part = op1->decimal_part->next;
        }
        // 두 소수 부분의 합을 Push, 10 이상이면 -10을 하고 다음 자릿 수의 합에 +1
        int sum = op1->decimal_part->digit + op2->decimal_part->digit;
        while (op1->decimal_part->next != NULL) {
            op1->decimal_part = op1->decimal_part->next;
            op2->decimal_part = op2->decimal_part->next;
            if (sum >= 10) {
                if (op1->decimal_part->next == NULL)
                    tok = TRUE;
                sum -= 10;
                DecPartPush(&result, sum);
                sum = op1->decimal_part->digit + op2->decimal_part->digit + 1;
            } else {
                DecPartPush(&result, sum);
                sum = op1->decimal_part->digit + op2->decimal_part->digit;
            }
        }
    } else {
        // 소수 부분의 차이만큼 긴 소수의 숫자 Push
        for (int i = 0; i < (-1) * decimal_gap; ++i) {
            DecPartPush(&result, op2->decimal_part->digit);
            op2->decimal_part = op2->decimal_part->next;
        }
        // 두 소수 부분의 합을 Push, 10 이상이면 -10을 하고 다음 자릿 수의 합에 +1
        int sum = op1->decimal_part->digit + op2->decimal_part->digit;
        while (op2->decimal_part->next != NULL) {
            op1->decimal_part = op1->decimal_part->next;
            op2->decimal_part = op2->decimal_part->next;
            if (sum >= 10) {
                sum -= 10;
                DecPartPush(&result, sum);
                sum = op1->decimal_part->digit + op2->decimal_part->digit + 1;
            } else {
                DecPartPush(&result, sum);
                sum = op1->decimal_part->digit + op2->decimal_part->digit;
            }
        }
    }

    if (integer_gap > 0) {
        // 정수 부분의 합을 Push, 10 이상이면 -10을 하고 다음 자릿 수의 합에 +1
        int sum = op1->integer_part->digit + op2->integer_part->digit;
        // tok가 TRUE면 첫 번째 자릿 수에서 +1
        if (tok == TRUE)
            sum++;
        while (op1->integer_part->next != NULL) {
            op1->integer_part = op1->integer_part->next;
            op2->integer_part = op2->integer_part->next;
            if (sum >= 10) {
                sum -= 10;
                IntPartPush(&result, sum);
                sum = op1->integer_part->digit + op2->integer_part->digit + 1;
            } else {
                IntPartPush(&result, sum);
                sum = op1->integer_part->digit + op2->integer_part->digit;
            }
        }
        // 정수 부분 길이의 차이만큼 긴 정수의 숫자 Push
        for (int i = 0; i < integer_gap; ++i) {
            DecPartPush(&result, op1->integer_part->digit);
            op1->integer_part = op1->integer_part->next;
        }
    } else {
        // 정수 부분의 합을 Push, 10 이상이면 -10을 하고 다음 자릿 수의 합에 +1
        int sum = op1->integer_part->digit + op2->integer_part->digit;
        // tok가 TRUE면 첫 번째 자릿 수에서 +1
        if (tok == TRUE)
            sum++;
        while (op1->integer_part->next != NULL) {
            op1->integer_part = op1->integer_part->next;
            op2->integer_part = op2->integer_part->next;
            if (sum >= 10) {
                sum -= 10;
                IntPartPush(&result, sum);
                sum = op1->integer_part->digit + op2->integer_part->digit + 1;
            } else {
                IntPartPush(&result, sum);
                sum = op1->integer_part->digit + op2->integer_part->digit;
            }
        }
        // 정수 부분 길이의 차이만큼 긴 정수의 숫자 Push
        for (int i = 0; i < (-1) * integer_gap; ++i) {
            DecPartPush(&result, op1->integer_part->digit);
            op1->integer_part = op1->integer_part->next;
        }
    }

    return result;
    
}

Num Minus(Num *op1, Num *op2) {

}

Num Multiply(Num *op1, Num *op2) {

}

Num Divide(Num op1, Num op2) {

}
