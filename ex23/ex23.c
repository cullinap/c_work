#include <stdio.h>
#include <string.h>
#include "dbg.h"
#include <time.h>


int normal_copy(char *from, char *to, int count)
{
	time_t start, end;
	start = time(NULL);
	int i = 0;

	for (i = 0; i < count; i++) {
		to[i] = from[i];
	}
	
	printf("\nTime taken to print normal cpy device copy is %.10f seconds", 
           difftime(end, start));

	return i;
}

int duffs_device(char *from, char *to, int count)
{
	time_t start, end;
	{
		
		start = time(NULL);
		int n = (count + 7) / 8; // if this was 100 / it would be be too short
		// this is an integer so it rounds

		// debug("n starts: %d, count: %d, count%%8: %d",
		// 		n, count, count % 8);

		switch (count % 8) {  // remainder 
			case 0: // this is like while true?
				do {
					*to++ = *from++;
					case 7:
					*to++ = *from++;
					case 6:
					*to++ = *from++;
					case 5:
					*to++ = *from++;
					case 4:
					*to++ = *from++;
					case 3:
					*to++ = *from++;
					case 2:
					*to++ = *from++;
					case 1:
					*to++ = *from++;
				} while (--n > 0);
		}
		end = time(NULL);
		printf("\nTime taken to print duff device copy is %.10f seconds", 
           difftime(end, start));
	}

	
	 

	return count;
}

int zeds_device(char *from, char *to, int count)
{
	time_t start, end;
	{
		start = time(NULL);
		int n = (count + 7) / 8;

		switch (count % 8) {
			case 0:
again:	  *to++ = *from++;

			case 7:
		  *to++ = *from++;
		   case 6:
		  *to++ = *from++;
		   case 5:
		  *to++ = *from++;
		   case 4:
		  *to++ = *from++;
		   case 3:
		  *to++ = *from++;
		   case 2:
		  *to++ = *from++;
		   case 1:
		  *to++ = *from++;
		  if (--n > 0)
		  	 goto again;
		}
		end = time(NULL);
		printf("\nTime taken to print zed's device copy is %.10f seconds", 
           difftime(end, start));
	}

	return count;
}

int valid_copy(char *data, int count, char expects)
{
	int i = 0;
	for (i = 0; i < count; i++) {
		if (data[i] != expects) {
			log_err("[%d] %c != %c", i, data[i], expects);
			return 0;
		}
	}

	return 1;
}

int main(int argc, char *argv[])
{
	char from[1000] = { 'a' };
	char to[1000] = { 'c' };
	int rc = 0;

	// set up the from to have some stuff
	memset(from, 'x', 1000);
	// set it to a failure mode
	memset(to, 'y', 1000);
	check(valid_copy(to, 1000, 'y'), "Not initialized right.");

	// use normal copy to

	rc = normal_copy(from, to, 1000);

	check(rc == 1000, "Normal copy failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "Normal copy failed.");

	// reset
	memset(to, 'y', 1000);

	// duffs version
	rc = duffs_device(from, to, 1000);

	check(rc == 1000, "Duff's device failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "Duff's device failed copy.");

	// reset
	memset(to, 'y', 1000);

	// my version
	rc = zeds_device(from, to, 1000);

	check(rc == 1000, "Zed's device failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "Zed's device failed copy.");

	return 0;

error:
	return 1;
}
































