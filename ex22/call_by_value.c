#include <stdio.h>

void func(int a, int b)
{
	a += b;
	printf("In func, a = %d b = %d\n", a,b);
}

int main(void)
{
	int x = 5, y = 7; // the value in main continues to have its original value

	func(x,y); // x = 12 y = 7
	printf("In main, x = %d y = %d\n", x, y); // x = 5 y = 7

	return 0;
}