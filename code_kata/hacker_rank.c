#include <stdio.h>

int main() {

	int x = 2;
	switch (x) {
		case 1: printf("one\n");
				break;
		case 2: printf("two\n");
				break;
		default: if (x % 2 == 0) {
					printf("even\n");
				 }
	}

	return 0;
}