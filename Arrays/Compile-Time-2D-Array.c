//PROGRAM FOR COMPILE TIME INITIALIATION OF A 2D ARRAY
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
//	Declaration and initialization of Array
	int array[2][3] = {{4,5,6},{1,2,3}};
	
	int i, j;
//	Displaying Array Elements
	printf("Elements in Array are:\n");
	for(i=0;i<2;i++) {
		for(j=0;j<3;j++) {
			printf("[%d][%d] = %d\n",i, j, array[i][j]);
		}
	}
	return 0;
}
