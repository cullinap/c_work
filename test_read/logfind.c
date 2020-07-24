#include <stdio.h>

int main()
{
	int c;
	FILE *file;
	file = fopen("test.log", "r");
	if (file) {
		while (( c = getc(file)) != EOF)
			putchar(c);
		fclose(file);
	}
}