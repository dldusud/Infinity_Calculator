#ifndef __INF_CALC_H__
#define __INF_CALC_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE    1
#define FALSE   0

typedef struct _digit {         // 리스트
    int digit;
    struct _digit * next;
} Digit, * pDigit;

typedef struct _number {
    int integer_part_size;
    int decimal_part_size;
    Digit * integer_part;
    Digit * decimal_part;
    int positive;
} Num, * pNum;

typedef struct _cNode {         // char Node
    char data;
    struct _cNode * next;
} cNode, *pcNode;

typedef struct _nNode {         // num Node
    Num num;
    struct _nNode * next;
} nNode, *pnNode;

typedef struct list {       // 후위식 저장 리스트
    cNode * head;
    cNode * tail;
} List, * pList;

void ListInit(List * plist);
void Insert(List * plist, List data);
char Remove(List * plist);

List pListInit(pList * plist);
void pInsert(pList * plist, pList data);
char pRemove(pList * plist);

typedef struct _operand {       // operand stack
    nNode * head;
} Operand, *pOperand;

typedef struct _operator {      // operator stack
    cNode * head;
} Operator, *pOperator;

void OperatorInit(Operator * pstack);            // 스택 초기화
int OperatorIsEmpty(Operator * pstack);         // 스택이 비어있는지 확인
void OperatorPush(Operator * pstack, char data); // 스택의 push연산
char OperatorPop(Operator * pstack);            // 스택의 pop 연산
char OperatorPeek(Operator * pstack);           // 스택의 peek연산 -> 가장 위에있는 data 확인

void OperandInit(pOperand * pstack);             // 스택 초기화
int OperandIsEmpty(pOperand * pstack);           // 스택이 비어있는지 확인
void OperandPush(pOperand * pstack, Num data);  // 스택의 push연산
Num OperandPop(pOperand * pstack);              // 스택의 pop 연산
Num OperandPeek(pOperand * pstack);             // 스택의 peek연산 -> 가장 위에있는 data 확인

#endif