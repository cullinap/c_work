#include <stdio.h>

int main()
{
	int mark[] = {19, 10, 8, 17, 9};

	for (int i = 0; i < 5; i++){
		printf("mark[%d] is %d at %p \n", i, mark[i], &mark[i]);
	}
	return 0;
}

