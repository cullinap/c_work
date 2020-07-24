#include <stdio.h>
#include <string.h>

int main()
{
	char a[]="Program";
	char b[]={'P','r','o','g','r','a','m','\0'};

	printf("Length of string a = %ld \n", strlen(a));
	printf("Length of string b = %ld \n", strlen(b));

	return 0;
}