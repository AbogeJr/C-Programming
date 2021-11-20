//QUEUE IMPLEMENTATION USING ARRAYS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = rear = -1, i;

int enQueue() {
	if(rear == SIZE-1) {
		printf("Queue Overflow!\n");
	}
	else {
		int data;
		printf("Enter element to add to queue:\n");
		scanf("%d", &data);
		rear++;
		queue[rear] = data;
	}
}

void deQueue() {
	
}


int main(int argc, char *argv[]) {
	
	
	
	return 0;
}
