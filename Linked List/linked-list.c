#include <stdio.h>
#include <stdlib.h>

struct node {
		int data;
		struct node *next;
	};

void count_nodes(struct node *head){
	int count=0;
	struct node *ptr=NULL;
	if(head==NULL){
		printf("Empty List!\n");
	}
	ptr=head;
	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}
	printf("Linked list has %d node(s)\n\n",count);
}

void print_data(struct node *head){
	if(head==NULL){
		printf("List is Empty!");
	}
	struct node *ptr=head;
	while(ptr!=NULL){
		printf("%d - ",ptr->data);
		ptr = ptr->next;
	}
}	
int main(int argc, char *argv[]) {
	
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->data=10;
	head->next=NULL;
	
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data=5;
	temp->next=NULL;
	head->next=temp;
	
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=15;
	temp->next=NULL;
	head->next->next=temp;
	
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=20;
	temp->next=NULL;
	head->next->next->next=temp;
	
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=50;
	temp->next=NULL;
	head->next->next->next->next=temp;
	
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=18;
	temp->next=NULL;
	head->next->next->next->next->next=temp;
	
	count_nodes(head);
	print_data(head);
	return 0;
}
