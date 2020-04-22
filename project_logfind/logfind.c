#include <stdio.h>
#include <string.h>
#include <stdlib.h> // explicit def of malloc


// @TODO
// add  argc arguments 
// iterate through files and return filename that contains kw
// take in multiple words
// add -o argument
// look into glob
// return matching lines

int main(int argc, char * argv[])
{
	long length; // this can be long but set to int for now
	char *buffer = 0;
	char *word = argv[1];

	if (argc < 1) {
		printf("Enter a word to find"); // work on this 
	}

	FILE *file;
	file = fopen("test.txt", "rb");

	if(file) {
		fseek(file, 0, SEEK_END); // Get the end of the file so that ftell can get the length
		length = ftell(file); // determine the length and store as var
		fseek(file, 0, SEEK_SET); // Get back to the begin of file
		buffer = malloc(length); // create buffer n length 

		if(buffer) {
			fread(buffer, 1, length, file);
		}

		fclose(file);
	}

	if(buffer) {
		if(strstr(buffer, word) != NULL) {
			printf("text \n");
		} else {
			printf("no word \n");
		}
	}
}













