#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inf_calc.h"

#define SIZE 10000

void Elim(char *, char);

char* calculator(char *expr) {
	Stack operand;
	Stack operator;
	char *num[SIZE] = { NULL, };
	int num_len[] = { 0, };
	int decimal_len[] = { 0, };
	
	// 공백을 기준으로 문자열을 자름
	char *ptr = strtok(expr, " ");
	
	int i = 0;
	while (ptr != NULL) {
		num[i] = ptr;
		i++;

		ptr = strtok(NULL, " ");
	}
	
	// 각 수의 전체 길이
	for (int i = 0; num[i] != NULL; ++i)
		num_len[i] = strlen(num[i]);
	
	// 각 수의 소수 부분의 길이
	for (int i = 0; num[i] != NULL; ++i) {
		char *decimal_part = strchr(num[i], '.');
		decimal_len[i] = strlen(decimal_part) - 1;
	}
	
	// 계산을 위해 각 수에서 소숫점 삭제, 결과 출력할 때  decimal_len에 따라 다시 소숫점  추가
	for (int i = 0; i != NULL; ++i)
		Elim(num[i], '.');

}

// 문자열에서 특정 문자를 삭제하는 함수
void Elim(char *str, char ch) {
	for (; *str != '\0'; str++) {
		if (*str == ch) {
			strcpy(str, str + 1);
			str--;
		}
	}
}
