#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node *addToEmpty(int data) {
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = temp;
	return temp;
}

struct node *addAtBeg(struct node *tail, int data) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = tail->next;
	tail->next = temp;
	return tail; 
}

struct node *addAtEnd(struct node *tail, int data) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	
	temp->next = tail->next;
	tail->next = temp;
	tail = tail->next;
	
	return tail;
}

struct node *addAfterPos(struct node *tail, int data, int pos) {
	struct node *ptr = tail->next, *temp = (struct node*)malloc(sizeof(struct node));
	temp->data =  data;
	temp->next = NULL;
	
	while(pos>1) {
		ptr = ptr->next;
		pos--;
	} 
	temp->next = ptr->next;
	ptr->next = temp;
	if(ptr==tail) {
		tail = tail->next;
	}
	
	return tail;
}

struct node *createList(struct node *tail) {
	int num, i, data;
	printf("\nEnter number of nodes:\n");
	scanf("%d", &num);
	if(num==0)
		return tail;
	printf("\nEnter data for node no. 1: ");
	scanf("%d",&data);
	tail = addToEmpty(data);
	
	for(i=2;i<=num;i++)
	{
		printf("\nEnter data for node no. %d: ",i);
		scanf("%d",&data);
		tail = addAtEnd(tail, data);
	}
	printf("\nList Created!\n");
	return tail;
}

struct node *delFirst(struct node *tail) {
		if(tail==NULL){
			return tail;
		}
		else if(tail->next==tail){
			free(tail);
			tail = NULL;
			return tail;
		}
		else{
		struct node *temp = NULL;
		temp = tail->next;
		tail->next = temp->next;
		free(temp);
		temp=NULL;
		return tail;
		}
}

struct node *delLast(struct node *tail) {
		struct node *temp = NULL;
		temp=tail->next;
		while(temp->next!=tail){
			temp = temp->next;
		}
		temp->next=tail->next;
		free(tail);
		tail = temp;
		return tail;
}

struct node *delInt(struct node *tail, int pos) {
	struct node *temp, *temp2;
	temp = NULL;
	temp2 = NULL;
	
	temp = tail->next;
	
	while(pos>2) {
		temp=temp->next;
		pos--;
	}
	temp2=temp->next;
	temp->next=temp2->next;
	
	if(temp2==tail)
		tail = temp;
	free(temp2);
	temp2=NULL;
	return tail;
}

struct node *deleteNode(struct node *tail, int pos) {
	int positon = pos;
	if(tail==NULL)
		return tail;
	
	if(pos==1){
		tail = delFirst(tail);
	}
	else{
		delInt(tail, pos);
	}	
	return tail;
}

int searchElement(struct node *tail, int elem) {
	int index = 0;
	struct node *ptr = tail->next;
	if(tail==NULL){
		return -2;
	}
	do {
		if(ptr->data==elem){
			return index;
		}
		ptr = ptr->next;
		index++;
	}
	while(ptr!=tail->next);
	return -1;
}

void print(struct node *tail) {
	struct node *ptr = tail->next;
	printf("\n");
	do {
		printf("%d - ",ptr->data);
		ptr = ptr->next;
	}
	while(ptr!=tail->next);
	printf("\n");
}

int main() {
	int choice, data, pos, elem, index;
	struct node *tail = NULL;
start:	
	printf("\nSelect an Option:\n");
	printf("1.Create List\n2.Print nodes\n3.Add at Begginning\n4.Add at End\n5.Add after Position\n6.Delete node\n7.Search for element\n8.exit\n\n");
	scanf("%d",&choice);
	
	switch(choice) {
		case 1:
			tail = createList(tail);
			break;
		case 2:
			printf("Nodes in the list are:");
			print(tail);
			break;
		case 3:
			printf("Enter data to be added:\n");
			scanf("%d", &data);
			tail = addAtBeg(tail, data);
			break;
		case 4:
			printf("Enter data to be added:\n");
			scanf("%d", &data);
			tail = addAtEnd(tail, data);
			break;	
		case 5:
			printf("Enter data to be added:\n");
			scanf("%d", &data);
			printf("Enter position after which to be added:\n");
			scanf("%d", &pos);
			tail = addAfterPos(tail, data, pos);
			break;
		case 6:
			printf("\nEnter position to delete:\n");
			scanf("%d",&pos);
			tail = deleteNode(tail, pos);
			break;
		case 7:
			printf("\nEnter element to be searched for:");
			scanf("%d",&elem);
			index = searchElement(tail, elem);
			if(index==-1){
				printf("\nNot Found!\n");
			}
			else if(index==-2){
				printf("\nList is Empty!\n");
			}	
			else{
				printf("\nElement %d is at index: %d\n", elem, index);
			}
		case 8:
			exit(0);
			break;			
		default:
			printf("Invalid choice!");
			break;
					
	}
goto start;	
	return 0;
}
