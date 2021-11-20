//STACK IMPLEMENTATION USING ARRAYS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE];
int i, top = -1;

int push(int item) {
	if(top==SIZE-1) {
		printf("Stack is full!\n");
	}
	else {
		top++;
		stack[top] = item;
	}
}

void pop() {
	if(top==-1) {
		printf("Stack is Empty!\n");
	}
	else {
		printf("Popped %d\n", stack[top]);
		top--;
	}
}

void display() {
	printf("Stack elements are:\n");
	for(i=top;i>=0;i--) {
		printf("[%d] - %d\n", i, stack[i]);
	}
}

int main(int argc, char *argv[]) {
	while(1) {
		int choice, data;
		printf("\nSelect an option:\n1.push\n2.pop\n3.display\n4.exit\n");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("Enter element to push:\n");
				scanf("%d", &data);
				push(data);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4: 
				exit(0);
				break;
			default:
				printf("Invalid choice!\n");
				exit(0);				
		}
	}
	return 0;
}
