#include <stdio.h>
#include <stdlib.h>

struct node {
		int data;
		struct node *next;
	};
	
void count_nodes(struct node *head);

void print_data(struct node *head);

void add_to_end(int node_data, struct node *head);

int main(int argc, char *argv[]) {
	int choice,val;
	
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
	
	selection:
		
	printf("\n\nPress 1 to add node\n\nPress 2 to exit\n");
	scanf("%d",&choice);
	
	switch(choice) {
		case 1: 
		printf("Enter value to be added to list:\n");
		scanf("%d",&val);
		add_to_end(val,head);
		break;
		
		case 2:
		exit(0);
		break;	
	}
	count_nodes(head);
	print_data(head);
	goto selection;	
	return 0;
}

void count_nodes(struct node *head) {
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

void print_data(struct node *head) {
	if(head==NULL){
		printf("List is Empty!");
	}
	struct node *ptr=head;
	while(ptr!=NULL){
		printf("%d - ",ptr->data);
		ptr = ptr->next;
	}
}

void add_to_end(int node_data, struct node * head) {
	struct node *temp, *ptr;
	ptr = head;
	
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=node_data;
	temp->next=NULL;
	
	
	while(ptr->next!=NULL) {
		ptr=ptr->next;
	}
	ptr->next = temp;
	
	printf("Node added!\n");
	printf("%d\n\n",node_data);
}

