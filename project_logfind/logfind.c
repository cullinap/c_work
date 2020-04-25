#include <stdio.h>
#include <string.h>
#include <stdlib.h> // explicit def of malloc
#include <dirent.h>

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


int main(void) 
{ 

  DIR *p;
  struct dirent *pp;     
  p = opendir ("./");

  if (p != NULL)
  {
    while ((pp = readdir (p))!=NULL) {
      int length = strlen(pp->d_name);
      if (strncmp(pp->d_name + length - 4, ".txt", 4) == 0) {
      	  puts(pp->d_name);
          FindWord("text", pp->d_name);
      }
    }

    (void) closedir (p);
  } 
} 




