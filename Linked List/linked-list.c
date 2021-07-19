#include <stdio.h>
#include <stdlib.h>

struct node {
		int data;
		struct node *next;
	};
	
void count_nodes(struct node *head);

void print_data(struct node *head);

struct node * add_to_end(int node_data, struct node *head);

struct node * add_to_empty(int node_data, struct node *head);

struct node * add_to_beg(int node_data, struct node * head);

struct node * add_after_pos(int node_data, int pos, struct node * head);

struct node * reverse_list(struct node * head);

void del_pos(struct node **head, int pos);

struct node * create_list(struct node* head);

int main() {
	int choice, data, pos;
	struct node *head = NULL;
start:	
	printf("\n\nSelect a function:\n1.Create List\n2.Add node to beginning\n3.Add node to end\n4.Add node after position\n5.Print data\n6.Reverse list\n7.Delete node at position\n8.Exit\n\n");
	scanf("%d",&choice);
	
	switch(choice) {
		case 1:
			head = create_list(head);
			printf("\nLinked list created!\n");
			break;
		case 2:
			printf("\nEnter data to be added to beginning of list: ");
			scanf("%d",&data);
			head =	add_to_beg(data, head);
			break;
		case 3:
		    printf("\nEnter data to be added to end of list: ");
			scanf("%d",&data);
			head =	add_to_end(data, head);
			break;
		case 4:
			printf("\nEnter position: ");
			scanf("%d",&pos);
			printf("\nEnter node data: ");
			scanf("%d",&data);
			head =	add_after_pos(data, pos , head);
			break;
		case 5:
			printf("\nLinked list contains the following nodes:\n\n");
			print_data(head);
			break;
		case 6:
			head = reverse_list(head);	
			break;
		case 7:
			printf("\nEnter position to be deleted:\n");
			scanf("%d",&pos);
			del_pos(&head,pos);
			break;	
		case 8:
			exit(0);
			break;
		default:
			printf("Invalid Choice!");	
			break;			
	}
	
goto start;
	return 0;
}

void count_nodes(struct node *head) {
	int count=0;
	struct node *ptr=head;
	if(ptr==NULL){
		printf("List is Empty!\n");
	}
	else {
	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}
	printf("Linked list has %d node(s)\n\n",count);
	}
}

void print_data(struct node *head) {
	struct node *ptr=head;
	if(ptr==NULL){
		printf("List is Empty!");
	}
	else {
	while(ptr!=NULL){
		printf("%d - ",ptr->data);
		ptr = ptr->next;
	}
    }
}

struct node * add_to_beg(int node_data, struct node * head) {
	struct node *ptr = head;
	if(ptr==NULL) {
		head = add_to_empty(node_data, head);
	}
	else {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = node_data;
	temp->next = ptr;
	head = temp;
	}
	return head;
}

struct node* add_to_end(int node_data, struct node * head) {
	struct node *ptr, *temp = (struct node*)malloc(sizeof(struct node));
	temp->data=node_data;
	temp->next=NULL;
	ptr = head;
	while(ptr->next!=NULL) {
		ptr=ptr->next;
	}
	ptr->next=temp;
	return head;
}

struct node * add_to_empty(int node_data, struct node *head) {
	head = (struct node *)malloc(sizeof(struct node));
	head->data = node_data;
	head->next = NULL;	
	return head;
}

struct node * add_after_pos(int node_data, int pos, struct node * head) {
	struct node *ptr = head;
	struct node *ptr2;
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->data=node_data;
	temp->next=NULL;
	while(pos!=1) {
		ptr = ptr->next;
		pos--;
	}
	ptr2=ptr->next;
	ptr->next=temp;
	temp->next=ptr2;
	return head;	
}

struct node * reverse_list(struct node * head) {
	struct node *ptr1 = NULL, *ptr2 = NULL;
	
	while(head!=NULL) {
		ptr2 = head-> next;
		head -> next = ptr1;
		ptr1 = head;
		head = ptr2;
	}
	 head = ptr1;
	
	printf("\n\nList Reversed!\n\n");
	
	return head;
}

void del_pos(struct node **head, int pos) {
	int position = pos;
	struct node * current = *head;
	struct node * previous = *head;
	
	if(*head == NULL) {
		printf("List is Empty!");
	}
	else if(pos == 1) {
		*head = current->next;
		free(current);
		current = NULL;
	}
	else {
		while(pos!=1) {
			previous = current;
			current = current -> next;
			pos--;
		}
		previous->next = current->next;
		free(current);
		current = NULL;
		printf("\nNode %d deleted!\n",position);
	}
}

struct node * create_list(struct node* head) {
	int n, i,data;
	printf("\nEnter number of elements:\n");
	scanf("%d",&n);
	
	if(n==0) {
		return head;
	}
	else {
		printf("Enter data for element no. 1: ");
		scanf("%d",&data);
		head=add_to_empty(data,head);
		
		for(i=1;i<n;i++) {
			printf("Enter data for element no. %d: ", i+1);
			scanf("%d", &data);
			add_to_end(data, head);
		}
		return head;
	}
}


