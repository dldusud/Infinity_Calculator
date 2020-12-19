#include <stdio.h>
#include <stdlib.h>
#include "InfinityCalculator.h"

void DigitInit(Digit * pDigit) {            // Digit 초기화
    pDigit->digit = 0;
    pDigit->next = NULL;
}


void OperandInit(pOperand * pstack) {            // 스택 초기화
    pstack->head = NULL;
}

int OperandIsEmpty(pOperand * pstack) {              // 스택이 비어있는지 확인
    if (pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void OperandPush(pOperand * pstack, Num data) {      // 스택의 push연산
    nNode * newNode = (nNode *)malloc(sizeof(nNode));

    newNode->num = data;
    newNode->next = pstack->head;

    pstack->head = newNode;
}

Num OperandPop(pOperand * pstack) {                 // 스택의 pop 연산
    Num rdata;
    nNode* rnode;

    if (OperandIsEmpty(pstack)) {
        printf("stack memory error");
        exit(-1);
    }

    rdata = pstack->head->num;
    rnode = pstack->head;

    pstack->head = pstack->head->next;
    free(rnode);

    return rdata;
}

Num OperandPeek(pOperand * pstack) {                 // 스택의 peek 연산
    if (OperandIsEmpty(pstack)) {
        printf("stack memory error");
        exit(-1);
    }
    return pstack->head->num;
}

void OperatorInit(Operator * pstack) {            // 스택 초기화
    pstack->head = NULL;
}

int OperatorIsEmpty(Operator * pstack) {              // 스택이 비어있는지 확인
    if (pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void OperatorPush(Operator * pstack, char data) {      // 스택의 push연산
    cNode * newNode = (cNode *)malloc(sizeof(cNode));

    newNode->data = data;
    newNode->next = pstack->head;

    pstack->head = newNode;
}

char OperatorPop(Operator * pstack) {                 // 스택의 pop 연산
    char rdata;
    nNode* rnode;

    if (OperatorIsEmpty(pstack)) {
        printf("stack memory error");
        exit(-1);
    }

    rdata = pstack->head->data;
    rnode = pstack->head;

    pstack->head = pstack->head->next;
    free(rnode);

    return rdata;
}

char OperatorPeek(Operator * pstack) {                 // 스택의 peek 연산
    if (OperatorIsEmpty(pstack)) {
        printf("stack memory error");
        exit(-1);
    }
    return pstack->head->data;
}

pNum NumInit(void) {                // Num 초기화
    pNum num = malloc(sizeof(cNode));
    num->integer_part = NULL;
    num->integer_part_size = 0;
    num->decimal_part = NULL;
    num->decimal_part_size = 0;
    num->positive = TRUE;
    return num;
}


void ExpInit(Postfix * plist) {
    plist->head = NULL;
    plist->tail = NULL;
}

void ExpInsert(Postfix * plist, char data) {
    cNode * newNode = (cNode*)malloc(sizeof(cNode));
    newNode->data = data;
    newNode->next = NULL;

    if (plist->head == NULL) {
        plist->head = newNode;
    }
    else {
        plist->tail->next = newNode;
    }
    plist->tail = newNode;
}

char LRemove(Postfix * plist) {
    char rdata;
    cNode * rnode;

    if (plist->head == NULL) {
        printf("list memory error");
        exit(-1);
    }

    rdata = plist->head->data;
    rnode = plist->head;

    plist->head = plist->head->next;
    free(rnode);

    return rdata;
}

