#include <stdio.h>

int main(int argc, char *argv[])
{
	char *name = "abcd";
	name[0] = 100;

	printf("name each: %d %d %d %d\n", name[0], name[1], name[2], name[3]);

	return 0;
}