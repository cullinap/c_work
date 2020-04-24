#include <stdio.h>
#include <string.h>
#include <stdlib.h> // explicit def of malloc
#include "dbg.h"
#include <errno.h>


// @TODO
// get the line that the text falls on 
// iterate through files and return filename that contains kw
// take in multiple words
// add -o argument
// look into glob
// return matching lines

// int argc, char * argv[]

void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	exit(1);
}

int count_lines(FILE *file)
{
	char z;
	int ctr = 0;

	for (z = getc(file); z != EOF; z = getc(file))
			if (z == '\n')
				ctr += 1;

	return ctr;	
}



int main(int argc, char *argv[])
{

	if (argc < 2)
		die("enter a word to search for");

	long length; // this can be long but set to int for now
	char *buffer = 0;
	char input[100];
	char *word =  strcpy(input, argv[1]);


	FILE *file;
	file = fopen("test.txt", "rb"); // add filename to this
	int lines = count_lines(file);

	if(file) {
		fseek(file, 0, SEEK_END); // Get the end of the file so that ftell can get the length
		length = ftell(file); // determine the length and store as var
		fseek(file, 0, SEEK_SET); // Get back to the begin of file
		buffer = malloc(length); // create buffer n length

		if(buffer) {
			fread(buffer, 1, length, file);
		}
	}

	for (i = 1; i < lines; i++)
	{
		if(buffer) {
			if(strstr(buffer, word) != NULL) {
				printf("text \n");
				printf("the lines in the file are: %d\n", lines); 
			} else {
				printf("no word \n");
			}
		}


	}


	fclose(file);

	return 0;
	
}













