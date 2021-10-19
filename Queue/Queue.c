#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5 //macro definition
//Queue data structure implementation in C
int queue[CAPACITY];
int front = 0;
int rear = 0;

void enQueue(int data) {
	if(rear==CAPACITY) {
		printf("Queue is full!\n");	
	}
	else {
		queue[rear] = data;
		rear++;
	}
}

int deQueue() {
	if(front==rear) {
		printf("Queue is Empty!\n");
	}
	else {
		int i;
		for(i=0;i<rear;i++) {
			queue[i]=queue[i+1];
		}
		rear--;
	}
	return queue[rear];
}

int main() {
	int choice, elem;
	
	while(1) {
	printf("Select an option:\n1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\n");
	scanf("%d",&choice);
	
	switch(choice) {
		case 1:
			printf("Enter data to add to Queue:\n");
			scanf("%d", &elem);
			enQueue(elem);
			printf("Element %d added to queue\n", elem);
			break;
		case 2:
			printf("Dequeueing...\n");
			printf("Element %d at rear\n", deQueue());
			break;
		case 3:
			printf("Traversing...\n");
			break;
		case 4:
			exit(1);
			break;
		default:
			printf("Invalid Choice!\n");				
	}
	
}
	return 0;
}
