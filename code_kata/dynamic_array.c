#include <stdio.c>
// driver function
int main(void) {
	int size;
	printf("\nEnter the size of the array: ");
	scanf("%d", &size);

	int *A;
	
	// int has size of 4 bytes * n of int
	// so if user enters 4 it would be 4 * 5 = 20
	// malloc returns void pointer so we typecast it
	// into an integer pointer

	A = (int*)malloc(size * sizeof(int)); 
	printf("\nEnter the values of the array: ");

	int i;
	for (i=0; i < size; i++) {
		scanf("%d", &A[i]);
	}

}