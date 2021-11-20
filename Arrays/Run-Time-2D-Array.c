//PROGRAM FOR RUNTIME INITIALIZATION OF A 2D ARRAY
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
//	Declaration of Array
	int array[2][3];
	int i, j;
	
//	Initializing the Array
	printf("Enter 6 numbers:\n");
	for(i=0;i<2;i++) {
		for(j=0;j<3;j++) {
			scanf("%d", &array[i][j]);
		}
	}	
//	Displaying Array Elements
	printf("Elements in Array are:\n");
	for(i=0;i<2;i++) {
		for(j=0;j<3;j++) {
			printf("[%d][%d] = %d\n",i, j, array[i][j]);
		}
	}
	return 0;
}

