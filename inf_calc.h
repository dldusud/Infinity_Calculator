#ifndef __INF_CALC_H__
#define __INF_CALC_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Stack.h"
#include "LinkedList.h"

#define TRUE    1;
#define FALSE   0;

typedef struct _digit {
    int digit;
    struct _digit * next;
} Digit;

typedef struct _number {
    int integer_part_size;
    int decimal_part_size;
    Digit * integer_part;
    Digit * decimal_part;
    int positive;
} Num;

List inf_to_pos(char* infix_expression);     // 중위 연산식을 후위 연산식으로 변환
Num calculator(char* postfix_expression);   // 후위 연산식을 계산
void print_result(Num result);              // 계산한 결과 출력

#endif
