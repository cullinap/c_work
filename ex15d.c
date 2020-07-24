#include <stdio.h>

int main()
{
	int* pc, c;

	//pc --> || c
	c = 22;
	printf("Address of c: %p\n", &c); //0x---
	printf("Value of c: %d\n\n", c); //22

	//pc --> c = 22
	//point pc to c pc --> c
	pc = &c;
	printf("Address of pointer pc: %p\n", pc); //0x---
	printf("Content of pointer pc: %d\n\n", *pc); //22

	//pc --> c = 11
	//change value of c to 11 (pc still pointed to pc)
	c = 11;
	printf("Address of pointer pc: %p\n", pc); //0x---
	printf("Content of pointer pc: %d\n\n", *pc); //11

	//pc --> c = 2
	//change the value at the memory location pointed by the pointer pc to 2
	*pc = 2;
	printf("Address of c: %p\n", &c); //0x---
	printf("Value of c: %d\n\n", c); //2

	return 0;
}