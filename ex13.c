#include <stdio.h>

//argc = argument count: stores the # of command line arguments including name of program
//argv = is an array of character pointers listing all the arguments

int main(int argc, char *argv[])
{
	int i = 0;

	//go through each string in argv
	//why am I skilling argv[0]?
	for (i = 1; i < argc; i++){
		printf("arg %d: %s\n", i, argv[i]);
	}

	//let's make our own array of strings
	char *states[] = {
		"California", "Oregon",
		"Washington", argv[1]
	};

	int num_states = 4;

	for (i = 0; i < num_states; i++){
		printf("state %d: %s\n", i, states[i]);
	}

	return 0;
}