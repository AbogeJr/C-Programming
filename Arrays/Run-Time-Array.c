//PROGRAM FOR RUNTIME INITIALIZATION OF AN ARRAY
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
//	Declaration of Array
	int arr[5];
	int i;
//	Initialization of array
	printf("Enter 5 numbers:\n");
	for(i=0;i<5;i++) {
		scanf("%d", &arr[i]);
	}
//	Displaying array elements
    printf("Elements in array are:\n");
	for(i=0;i<5;i++) {
		printf("[%d] = %d\n", i, arr[i]);
	}	
	return 0;
}
