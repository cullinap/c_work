#include <stdio.h>

//command line arguments
//argc is the number of commands passed
//argv pointer array which points to each argument passed to the program
int main(int argc, char *argv[])
{
	int i = 0;

	//if test
	if (argc == 1){
		printf("You only have one argument. You suck.\n");

	//else if test
	} else if (argc > 1 && argc < 4){
		printf("Here's your arguments:\n");

		//for loop, post-increment
		for (i=0; i < argc; i++){
			printf("%s", argv[i]);
		}
		printf("\n");

	//else
	} else {
		printf("You have too many arguments. You suck.\n");
	}

	return 0;

}