//PORGRAM FOR COMPILE-TIME INITIALIZATION OF AN ARRAY
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
//	Declaration and intialization of array
	int arr[5] = {1,2,3,4,5};
	int i;
//	Displaying array elements
    printf("Elements in array are:\n");
	for(i=0;i<5;i++) {
		printf("[%d] = %d\n", i, arr[i]);
	}
	return 0;
}
