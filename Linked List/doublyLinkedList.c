#include <stdio.h>
#include <stdlib.h>

//IMPLEMENTATION OF DOUBLY LINKED LIST

struct node {	//Node structure
	struct node * prev;						
	int data;                                
	struct node * next;                     
};

struct node *addToEmpty(struct node * head, int data) {		//Initializes the list (using head pointer)		
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	temp->data=data;
	head = temp;
	return head;
}

struct node *addToBeg(struct node * head, int data) {	//Creates and adds node to the beginning of initialized list (head)
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	
	temp->next = head;
	head->prev = temp;
	head = temp;
	
	return head;
}

struct node *addToEnd(struct node * head, int data) {	//Creates and adds node to the end of initialized list
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

struct node * addAfterPos(struct node * head, int data, int position) {	//Creates and adds a node after the specified position		
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

struct node *createList(struct node *head) {	//Intergrates addToEmpty() and addToEnd() functions to create a doubly linked list
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

struct node *reverse_list(struct node *head) {     //Reverses the nodes of the linked list
	struct node * ptr1 = head;
	struct node * ptr2 = ptr1->next;
	
	ptr1->next = NULL;
	ptr1->prev = ptr2;
	
	 while(ptr2!=NULL) {
	 	ptr2->prev = ptr2->next;
		ptr2->next = ptr1;
		ptr1 = ptr2; 
		ptr2 = ptr2->prev;
	 }
	head = ptr1;
	return head;
}

void displayNodes(struct node * head) {	   //Prints the data of the nodes in the list
	if(head==NULL) {
		printf("No Nodes detected!\n\n");
	}
	else {
	printf("\n\nNodes in doubly linked list are:\n\n");
	struct node * ptr;
	ptr = head;
	while(ptr!=NULL) {
		printf("%d - ", ptr->data);
		ptr=ptr->next;
	}
	}
	printf("\n\n");
}

int main() {
	struct node* head = NULL;			//Initializing the head pointer. (To be used in the functions)
	int choice, data, pos;	
	printf("###Doubly linked list generator###\n\n");
start:	
	printf("Select a function:\n1.Create List\n2.Add to beginning\n3.Add to end\n4.Add after position\n5.Display Nodes\n6.Reverse list\n7.Exit\n\n");
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
			head = reverse_list(head);
			printf("\n\nList reversed\n\n");
			break;	
		case 7:
			exit(0);	
		default:
			printf("\nINVALID CHOICE!\n\n");
			break;				
	}
goto start; 		//Returns functionality to the beginning of the program
	return 0;
}

