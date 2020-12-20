#ifndef __INF_CALC_H__
#define __INF_CALC_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE    1;
#define FALSE   0;

typedef struct _digit {
    int digit;
    struct _digit * next;
} Digit, pDigit;

typedef struct _number {
    int integer_part_size;
    int decimal_part_size;
    Digit * integer_part;
    Digit * decimal_part;
} Num, *pNum;

typedef char Data;

typedef struct _node {
    Data data;
    struct _node * next;
} Node;

typedef struct _block {
    Num operand;
    struct _block * next;
} Block;

typedef struct _list {
    Node * head;
    Node * tail;
} List;

typedef struct _operator {
    Node * head;
} Operator;

typedef struct _operand {
    Block * head;
} Operand;

void ListInit (List * plist);
void LInsert (List * plist);
List LRemove (List * plist);

void OperatorInit (Operator * pOp);
int OperatorIsEmpty(Operand * pOp);
void OperatorPush (Operator * pOp);
Data OperatorPop (Operator * pOp);
Data OperatorPeek (Operand * pOp);

void OperandInit (Operand * pOp);
int OperandIsEmpty(Operand * pOp);
void OperandPush (Operand * pOp);
Num OperandPop (Operand * pOp);
Num OperandPeek (Operand * pOp);

#endif