#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5 //macro definition
//Stack data structure implementation in C
//pop()Deletes top element in stack
//push()Adds element to top of stack
//peek()Checks top element of stack
//traverse()Displays all elements of stack

int stack[CAPACITY];
int top=-1;  //used to indicate stck index

int isFull(int *data) { 
	if(top>=CAPACITY)
		return 1;
	else
		return 0;	
}
int isEmpty(int *data) {
	if(top<=0)
		return 1;
	else
		return 0;
}

int push(int num) { 
	top++;
	stack[top]=num;
	return stack[top];	
}

void pop() {
	top--;
}

int peek() {
	return stack[top];
}

void traverse(int *data) {
	int i;
	for(i=top;i>=0;i--) {
		printf("\n%d\n",stack[i]);
	}
}

int main() {
	int choice, elem;
	printf("Select an option:\n1. push()\n2 .pop()\n3. peek()\n4. Traverse()\n5. Exit\n\n");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			if(isFull(stack)){
				printf("Stack Full!\nCannot push!\n\n");
			}
			else{
			printf("Enter element to push:\n\n");
			scanf("%d",&elem);
			push(elem);
			printf("Pushed element: %d\n\n",stack[top]);
	    	}	
	        break;
	    case 2:
	    	if(isEmpty(stack)){
	    		printf("Stack is empty!\nCannot pop!\n\n");
			}
	    	else{
			printf("Whats poppin... (��_�):\n");
			pop();
			printf("Popped value!\n\n");
			}
	        break;
	        
		case 3:
			printf("Top element is %d\n\n",peek());
			break;
			
		case 4:
			if(isEmpty(stack)) {
				printf("Stack is empty!\n\n");
			}
			else{
				printf("Elements in stack are:\n");
			    traverse(stack);
			}
			break;

		case 5:
			printf("Exit\n");
			exit(0);
			break;

		default:
			printf("Invalid choice!");			    
	}
	main();
	return 0;
}
