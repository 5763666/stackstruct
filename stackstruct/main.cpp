#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK_SIZE 10  //ÇÊ
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) { return (s->top == -1); }

int is_full(StackType* s) { return (s->top == (MAX_STACK_SIZE - 1)); }


void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack Empty!\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Full!\n");
		return 0;
	}
	else return s->data[(s->top)--];
}

int main(void) {
	StackType s;
	init_stack(&s);

	printf("-----Using array-----\n");
	srand((unsigned int)time(NULL)); //ÇÊ

	for (int i = 0; i <= 30; i++) {
		if (i < 10) printf("[ %d] ", i);
		else printf("[%d] ", i);

		int rand_num = rand() % 100 + 1; //ÇÊ

		if (rand_num % 2 == 0) {
			printf("Push %d\n", rand_num);
			push(&s, i);

		}
		else {
			printf("Pop %d\n", pop(&s));
		}
	}

	return 0;
}