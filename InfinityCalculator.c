#include "InfinityCalculator.h"

#define TRUE        1
#define FALSE       0

void NumInit(Num * pnum) {
    pnum->integer_part_size = 0;
    pnum->decimal_part_size = 0;
    pnum->integer_part = NULL;
    pnum->decimal_part = NULL;
}

void IntPartInsert(Num * pnum, char data) {
    Digit newDigit = (Digit*)malloc(sizeof (Digit));

    newDigit.digit = data;
    newDigit->next = pnum->integer_part;

    pnum->integer_part = newDigit;
}

void DecPartInsert(Num * pnum, char data) {
    Digit newDigit = (Digit*)malloc(sizeof (Digit));

    newDigit.digit = data;
    newDigit->next = pnum->decimal_part;

    pnum->decimal_part = newDigit;
}



void ListInit(List * plist) {
    plist->head = NULL;
    plist->tail = NULL;
}

void LInsert(List * plist, char data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
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

char LRemove(List* plist) {
    LData rdata;
    LNode* rnode;

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

/* 피연산자 스택 */
void OperandInit(Operand * pOp) {
    pOp->head = NULL;
}

int OperandIsEmpty(Operand * pOp) {
    if (pOp->head == NULL)
        return TRUE;
    else
    return FALSE;
}

void OperandPush(Operand * pOp, Num data) {
    Block * newBlock = (Block*)malloc(sizeof(Block));

    newBlock->operand = data;
    newBlock->next = pOp->head;

    pOp->head = newBlock;
}

Num OperandPop(Operand * pOp) {
    Num rdata;
    Block * rblock;

    if (OperandIsEmpty(pOp)) {
        printf("stack memory error");
        exit(-1);
    }

    rdata = pOp->head->operand;
    rblock = pOp->head;

    pOp->head = pOp->head->next;
    free(rblock);

    return rdata;
}

Num OperandPeek(Operand * pOp) {
    if (OprandIsEmpty(&pOp)) {
        printf("stack memory error");
        exit(-1);
    }

    return pOp->head->operand;
}


/* 연산자 스택 */

void OperatorInit(Operator * pOp) {
    pOp->head = NULL;
}

int OperatorIsEmpty(Operator * pOp) {
    if (pOp->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void OperatorPush(Operator * pOp, char data) {
    Node * newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = pOp->head;

    pOp->head = newNode;
}

Data OperatorPop(Operator * pOp) {
    char rdata;
    Node * rnode;

    if (OperatorIsEmpty(pOp)) {
        printf("stack memory error");
        exit(-1);
    }

    rdata = pOp->head->data;
    rnode = pOp->head;

    pOp->head = pOp->head->next;
    free(rnode);

    return rdata;
}

Data OperatorPeek(Operator * pOp) {
    if (OperatorIsEmpty(pOp)) {
        printf("stack memory error");
        exit(-1);
    }
    return pOp->head->data;
}