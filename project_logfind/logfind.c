#include <stdio.h>
#include <string.h>
#include <stdlib.h> // explicit def of malloc
#include <dirent.h>
#include <errno.h>

void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	exit(1);
}


void FindWord(char *word , char *file) {
    char *line = NULL;
    size_t n = 0;
    FILE *f = fopen(file, "r");
    int ctr = 0;

    while (getline(&line, &n, f) != -1)
    {
    	ctr++;

        if (strstr(line , word ) != NULL)
        {
             printf("'%s' appears on line %d\n", word, ctr);
        }
    }
    
    fclose(f);
    free(line);
}


int main(int argc, char *argv[]) 
{ 
  if (argc < 1)
  	die("provide the term you wish to search for");

  int i = 0;

  for (i=1; i < argc; i++) {

  	DIR *p;
  	struct dirent *pp;     
  	p = opendir ("./");
  	
    if (p != NULL)
    {
    	
       	while (( pp = readdir(p)) !=NULL ) {
      		int length = strlen(pp->d_name);
      		if (strncmp(pp->d_name + length - 4, ".txt", 4) == 0) {
      	  		puts(pp->d_name);
          		FindWord(argv[i], pp->d_name);
        	}
      	}

      	(void) closedir (p);
    	} 
  	}


} 




