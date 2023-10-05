#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING_SIZE 100
#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct Stack{
	element stack[MAX_STACK_SIZE];
	int top; //구조체 값을 초기화할 수 없으므로 따로 만들어주어야함
}Stack;

//스택 
element stack[MAX_STACK_SIZE];
int top = -1;

int is_full(Stack* s) {
	return (s->top == (MAX_STACK_SIZE - 1)); //참이면 1 반환, 거짓이면 0 반환
}

void push(Stack* s, element item) {
	if (is_full(s)) {
		//printf  vs  fprintf
		fprintf(stderr, "스택 포화 에러\n"); // 에러 출력
		return;
	}
	else {
		s->stack[++(s->top)] = item;
	}
}

int is_empty(Stack* s) {
	return (s->top == -1); //참이면 1 반환, 거짓이면 0 반환
	//return (top < 0); //0과 관련된 비교문을 쓰면 최적화가 잘 되어있어서 더 빠름
}

element pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 포화 에러\n"); // 에러 출력
		exit(1); //0이 아닌 숫자를 넣어줘야함. 0을 넣게 되면 정상 종료가 됨
	}
	else {
		return s->stack[(s->top)--];
	}
}

element peek(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 포화 에러\n"); // 에러 출력
		exit(1); //0이 아닌 숫자를 넣어줘야함. 0을 넣게 되면 정상 종료가 됨
	}
	else {
		return s->stack[s->top];
	}
}

//void init_stack(StackType stack) { // stack=s --> s공간을 간접참조하지 못함
void init_stack(Stack* s) { //*stack==(main)s
	s->top = -1;
}

int main(void) {
	Stack s;

	init_stack(&s);

	for (int i = 1; i <= 10; i++) {
		push(&s, i);
		printf("push: %d\n", i);
	}

	for (int i = 1; i <= 10; i++)
		printf("pop: %d\n", pop(&s));

	free(s.stack);

}
