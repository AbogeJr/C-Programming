//STACK PROGRAM TO PRINT MY NAME IN REVERSE
#include <stdio.h>
#include <stdlib.h>

//DEFINING NODE STRUCTURE
struct Node {
	int data;
	struct Node* next;
};
//CREATING AN ALIAS FOR "struct Node"
typedef struct Node Node;
//FUNCTION TO CREATE FIRST NODE (INITIALIZE LINKED LIST)
Node *add_to_empty(Node *head, int data) {
	head = (Node*)malloc(sizeof(Node));
	head->data = data;
	head->next = NULL;
	printf("\nLinked List initialized!\n");
	return head;
}
//FUNCTION TO CREATE AND ADD NODE TO BEGINNING OF LINKED LIST
Node *add_to_front(Node *head, int node_data) {
	Node *ptr = head;
	if(ptr == NULL) {
		ptr = add_to_empty(ptr, node_data);
	}
	else {
		Node *temp = (Node*)malloc(sizeof(Node));
		temp->data = node_data;
		temp->next = head; 
		head = temp;
	}
	return head;
}
//FUNCTION TO CREATE AND ADD NODE TO END OF LINKED LIST
Node *add_to_end(Node *head, int data) {
	Node *ptr, *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	ptr = head;
	while(ptr->next!=NULL) {
		ptr = ptr->next;
	}
	ptr->next = temp;
	return head;
}
//FUNCTION TO DISPLAY LINKED LIST ITEMS
void display(Node *head) {
	Node *ptr=head;
	if(ptr==NULL){
		printf("List is Empty!");
	}
	else {
		printf("\nLinked List Items:\n");
		printf("[ ");	
		while(ptr!=NULL){
			printf("%d - ",ptr->data);
			ptr = ptr->next;
		}
		printf(" ]");
    }
}

int main(int argc, char *argv[]) {
	
	Node *head = NULL;
	
	head = add_to_empty(head, 69);
	head = add_to_end(head, 44);
	display(head);
	head = add_to_front(head, 74);
	display(head);
	return 0;
}
