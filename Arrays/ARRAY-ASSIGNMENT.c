//Write a C Program to:
//	1.Insert the following items into an array: 66,78,45,67,5 by inputting using scanf
//	2.Traverse the array items
//	3.Update the array item at position 4 to 789
//	4.Search for item 34 in the array
//	5.Delete item at position 3
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int arr[5];
	int i, k, pos, data, num, flag = 0;
	
	//Insertion
	printf("Enter Array Elements:\n");
	for(i=0;i<5;i++) {
		scanf("%d", &arr[i]);
	}
	
	//Traversing
	printf("Array Elements are:\n");
	for(i=0;i<5;i++) {
		printf("[%d] - %d\n", i, arr[i]);
	}
	
	//Updating 
	printf("Enter position to update:\n");
	scanf("%d", &pos);
	printf("Enter data:\n");
	scanf("%d", &data);
	arr[pos-1] = data;
	printf("[%d] updated to %d\n", pos-1, data);
	
	//Searching
	printf("Enter emlement to search:\n");
	scanf("%d", &num);
	for(i=0;i<5;i++) {
		if(arr[i]==num) {
			flag = 1;
			break;
		}
	}
	if(flag==1) {
		printf("Element %d found at index [%d]\n", num, i);
	}
	else {
		printf("Element not found!\n");
	}
	
	//Deletion
	printf("Enter element position to delete:\n");
	scanf("%d", &k);
	for(i=k-1;i<5;i++) {
		arr[i] = arr[i+1];
	}
	
	printf("\n\nArray Elements after deletion are:\n");
	for(i=0;i<5;i++) {
		printf("[%d] - %d\n", i, arr[i]);
	}
	
	return 0;
}
