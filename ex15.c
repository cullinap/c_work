d#include <stdio.h>

int main (int argc, char *argv[])
{
	// create two arrays we care about
	// store an these value in a variable called ages type int with a mem address
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	printf("the location of ages is %p \n", &ages);
	printf("the location of ages first variable is %p \n", &ages[0]);
	printf("the location of ages second variable is %p \n", &ages[1]);
	printf("######\n");
	int* pc;
	printf("pc is a pointer pointing to nothing right now\n");
	printf("######\n");
	pc = &ages[0];
	printf("pc now points address %p which is the same as %p \n", pc, &ages[0]);
	printf("######\n");
	printf("pc points to the value %d which is the same as %d \n", *pc, ages[0]);
	printf("######\n");
	printf("\n");
	// printf("the location of names is %p \n", &names);
	// printf("the value of the first string of names is %s \n", names[0]);
	// printf("the location of names first string is %p \n", &names[0]);

	printf("######\n");
	//new pointer
	int ages_two[] = { 23, 43, 12, 89, 2, 0 };

	//create a pointer called pc_ages and point to the first value of the array ages_two
	//
	for (int *pc_ages = ages_two; *pc_ages; ++pc_ages) {
		printf("value is: %d \n", *pc_ages);
	}



	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	// first way using indexing
	for (i = count - 1; i >= 0; i--) {
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	printf("---\n");

	//set up the points to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	//second way using pointers
	for (i = 0; i < count; i++) {
		printf("%s is %d years old.\n", 
			*(cur_name + i), *(cur_age + i));
	}

	printf("---\n");

	// third way, pointers are just arrays
	for (i = 0; i < count; i++) {
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
	}

	printf("---\n");

	//fourth way with pointers in a stupid complex way
	for (cur_name = names, cur_age = ages;
			(cur_age - ages) < count; cur_name++, cur_age++) {
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}

	return 0;
}










