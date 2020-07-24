#include <stdio.h>
#include <string.h>
#include <stdlib.h> // explicit def of malloc
#include <dirent.h>
#include <errno.h>
#include "dbg.h"


void FindWord(char *word , char *file) {
    char *line = NULL;
    size_t n = 0;
    FILE *f = fopen(file, "r");
    int ctr = 0;

    while (getline(&line, &n, f) != -1)
    {
    	ctr++;

        if (strstr(line , word) != NULL)
        {
             printf("'%s' appears on line %d\n", word, ctr);
        }
    }
    
    fclose(f);
    free(line);
}

void Iterate_Through_Files(char *term, char *file_type)
{
	DIR *p;
  	struct dirent *pp;     
  	p = opendir ("./");
  	
    if (p != NULL) {
    	
       	while (( pp = readdir(p)) !=NULL ) {
      		int length = strlen(pp->d_name);
      		if (strncmp(pp->d_name + length - 4, file_type, 4) == 0) {
      	  		puts(pp->d_name);
          		FindWord(term, pp->d_name);
        	}
      	}

      	(void) closedir (p);
    } 
}


int main(int argc, char *argv[]) 
{ 
  check(argc > 2, "USAGE: logind word word word")

  int i = 0;
  char *f_type = ".txt";

  for (i=1; i < argc; i++) {
  	Iterate_Through_Files(argv[i], f_type);
  }

error:
	return 1;

} 




