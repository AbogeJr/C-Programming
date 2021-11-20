//STACK PROGRAM TO PRINT MY NAME IN REVERSE
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

char stack[SIZE];
int i, top = -1;

int push(char item) {
	if(top==SIZE-1) {
		printf("Stack is full!\n");
	}
	else {
		top++;
		stack[top] = item;
	}
}

void display() {
	for(i=top;i>=0;i--) {
		printf("%c\n", stack[i]);
	}
}

int main(int argc, char *argv[]) {
	
//	PUSHING 'A-L-O-Y-S' INTO STACK
	push('A');
	push('L');
	push('O');
	push('Y');
	push('S');
//	DISPLAYING NAME IN REVERSE		
	display();		

	return 0;
}
