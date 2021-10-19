#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5 //macro definition
//Stack data structure implementation in C

int stack[CAPACITY];
int top=-1;  //used to indicate stack item index

int isFull(int *data) { //checks whether the stack is full (with respect to it's capacity)
	if(top>=CAPACITY-1)
		return 1;
	else
		return 0;	
}
int isEmpty(int *data) {  //checks whether the stack is empty (top would be at -1)
	if(top<=0)
		return 1;
	else
		return 0;
}

int push(int num) { //adss item onto stack
	top++;
	stack[top]=num;
	return stack[top];	
}

void pop() {		//deletes top item from stack
	top--;
}

int peek() {	//returns item on top of stack
	return stack[top];
}

void traverse(int *data) {	//displays items in the stack
	int i;
	for(i=top;i>=0;i--) {
		printf("[%d]= %d\n",i,stack[i]);
	}
}

int main() {
	int choice, elem;
start:	
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
			printf("Whats poppin... :\n");
			pop();
			printf("Your value!\n\n");
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
goto start;
	return 0;
}
