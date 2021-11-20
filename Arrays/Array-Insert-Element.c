//PROGRAM TO INSERT ELEMENT INTO ARRAY 
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
	
//	INSERTING ELEMENT
	printf("Enter position to be inserted into:\n");
	scanf("%d", &k);
	printf("Enter element to be inserted:\n");
	scanf("%d", &num);
	printf("Inserting element in position %d:\n", k);
	arr[k-1] = num;
	
//	DISPLAYING ARRAY AFTER INSERTION
	printf("Resultant Array:\n");
	for(i=0;i<5;i++) {
		printf("[%d] = %d\n",i,arr[i]);
	}
	
}
