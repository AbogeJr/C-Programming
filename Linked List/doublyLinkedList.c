#include <stdio.h>
#include <stdlib.h>

//IMPLEMENTATION OF DOUBLY LINKED LIST

struct node {											//Node structure
	struct node * prev;						
	int data;                                
	struct node * next;                     
};

struct node *addToEmpty(struct node * head, int data) {						//Initializes the linked list
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	temp->data=data;
	head = temp;
	return head;
}

struct node *addToBeg(struct node * head, int data) {						//Adds a node to the beginning of initialized linked list
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	
	temp->next = head;
	head->prev = temp;
	head = temp;
	
	return head;
}

<<<<<<< HEAD
struct node *addToEnd(struct node * head, int data) {
=======
struct node *addToEnd(struct node *head, int data) {						//Adds a node to the end of an initialized linked list
>>>>>>> d3421dd2965318d5c633a406d0acae7e9810e8c6
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

<<<<<<< HEAD
struct node * addAfterPos(struct node * head, int data, int position) {
=======
struct node * addAfterPos(struct node * head, int data, int position) {				//Adds a node after stated position in the list
>>>>>>> d3421dd2965318d5c633a406d0acae7e9810e8c6
	struct node *temp, *temp2;
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	temp = head;
	temp2 = NULL;
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	
	while(position!=1) {
		temp = temp->next;
		position--;
	}
	if(temp->next==NULL) {
		temp->next=newNode;
		newNode->prev=temp;
	}
	else{
	temp2 = temp->next;
	temp->next = newNode;
	temp2->prev = newNode;
	newNode->prev=temp;
	newNode->next=temp2;
	}
	return head;
}

<<<<<<< HEAD
struct node *createList(struct node *head) {
	int data, i, n;
	
	printf("Enter number of elements in list:\n");
	scanf("%d",&n);
	
	if(n==0) {
		return head;
	}
	
	printf("\n\nEnter data for node no. 1: ");
	scanf("%d",&data);
	head = addToEmpty(head,data);
	
	for(i=1;i<n;i++) {
		printf("\nEnter data for node no. %d: ",i+1);
		scanf("%d",&data);
		head = addToEnd(head, data);
	}
	return head;
}

void displayNodes(struct node * head) {
	if(head==NULL) {
		printf("No Nodes detected!\n\n");
	}
	else {
	printf("\n\nNodes in doubly linked list are:\n\n");
=======
void displayNodes(struct node * head) {								//Prints the linked list
>>>>>>> d3421dd2965318d5c633a406d0acae7e9810e8c6
	struct node * ptr;
	ptr = head;
	while(ptr!=NULL) {
		printf("%d - ", ptr->data);
		ptr=ptr->next;
	}
	}
	printf("\n\n");
}

<<<<<<< HEAD
int main() {
	struct node* head = NULL;
	int choice, data, pos;	
	printf("###Doubly linked list generator###\n\n");
start:	
	printf("Select a function:\n1.Create List\n2.Add to beginning\n3.Add to end\n4.Add after position\n5.Display Nodes\n6.Exit\n\n");
	scanf("%d",&choice);
	switch(choice) {
		case 1:
			head = createList(head);
			printf("\nList created successfully!\n\n");
			break;
		case 2:
			printf("\nEnter data to be added: ");	
			scanf("%d",&data);
			head = addToBeg(head,data);
			break;
		case 3:
			printf("\nEnter data to be added: ");	
			scanf("%d",&data);
			head = addToEnd(head,data);
			break;
		case 4:
			printf("Enter position: ");
			scanf("%d", &pos);
			printf("\nEnter data to be added: ");	
			scanf("%d",&data);
			head = addAfterPos(head, data, pos);
			break;
		case 5:
			displayNodes(head);
			break;
		case 6:
			exit(0);	
		default:
			printf("\nINVALID CHOICE!\n\n");
			break;				
	}
goto start;
	return 0;
=======
int main() {				//Samples
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
>>>>>>> d3421dd2965318d5c633a406d0acae7e9810e8c6
}

