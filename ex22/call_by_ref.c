#include <stdio.h>

void swapnum(int* i, int* j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

int main(void)
{
	int a = 10, b = 20;

	// passing parameters & modifying the object it points to
	swapnum(&a, &b);

	printf("a is %d and b is %d\n", a, b); // a = 20 b = 10
	return 0;
}