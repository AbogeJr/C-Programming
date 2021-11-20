//PROGRAM TO DELETE AN ELEMENT FROM ARRAY
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
//	DECLARATION AND INITIALIZATION OF ARRAY
	int arr[5];
	int i, num, k;
	printf("Enter 5 elements:\n");
	for(i=0;i<5;i++) {
		scanf("%d", &arr[i]);
	}
	
//	DISPLAYING ELEMENTS
	printf("Current Array:\n");
	for(i=0;i<5;i++) {
		printf("[%d] = %d\n",i,arr[i]);
	}
	
//	DELETING ELEMENT
	printf("Enter position to be deleted from:\n");
	scanf("%d", &k);
	printf("Deleteing element at position %d:\n", k);
	for(i=k-1;i<5;i++) {
		arr[i]=arr[i+1];
	}
	
//	DISPLAYING ARRAY AFTER DELETION
	printf("Resultant Array:\n");
	for(i=0;i<5;i++) {
		printf("[%d] = %d\n",i,arr[i]);
	}
	
}
