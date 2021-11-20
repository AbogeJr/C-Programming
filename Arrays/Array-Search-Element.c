//PROGRAM TO SEARCH FOR AN ELEMENT IN ARRAY
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int arr[5];
	int i, num, found = 0;
	printf("Enter 5 elements:\n");
	for(i=0;i<5;i++) {
		scanf("%d", &arr[i]);
	}
	
//	Displaying elements
	for(i=0;i<5;i++) {
		printf("[%d] = %d\n",i, arr[i]);
	}
	
//	Searching for element
	printf("\nEnter element to search:\n");
	scanf("%d", &num);
	for(i=0;i<5;i++) {
		if(arr[i]==num) {
			found = 1;
			break; 			//Break Loop when element is found
		}
	}
	if(found==1){
		printf("Element %d is at index [%d]", num, i);
	}
	else{
		printf("Element not found\n");
	}
	
	return 0;
}
