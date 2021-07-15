#include <stdio.h>
#include <stdlib.h>

//IMPLEMENTATION OF DOUBLY LINKED LIST

struct node {
	struct node * prev;						
	int data;                                
	struct node * next;                     
};

struct node *addToEmpty(struct node * head, int data) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	temp->data=data;
	head = temp;
	return head;
}

struct node *addToBeg(struct node * head, int data) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	
	temp->next = head;
	head->prev = temp;
	head = temp;
	
	return head;
}

struct node *addToEnd(struct node *head, int data) {
	struct node *ptr, *temp = (struct node*)malloc(sizeof(struct node));
	ptr = head;
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	
	while(ptr->next!=NULL) {
		ptr=ptr->next;
	}
	
	temp->prev = ptr;
	ptr->next=temp;
	return head;
}

void displayNodes(struct node * head) {
	struct node * ptr;
	ptr = head;
	while(ptr!=NULL) {
		printf("%d - ", ptr->data);
		ptr=ptr->next;
	}
}

int main() {
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head = addToEmpty(head, 25);
	head = addToEnd(head, 34);
	head = addToEnd(head, 14);
	head = addToEnd(head, 50);
	
	displayNodes(head);
	
	printf("\n\nAdding items to beginning...\n\n");
	
	head = addToBeg(head, 100);
	head = addToBeg(head, 200);
	head = addToBeg(head, 300);
	head = addToBeg(head, 400);
	
	displayNodes(head);
}

