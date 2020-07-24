#include "dbg.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	exit(1);
}

typedef int (*compare_cb)(int a, int b);

int *selection_sort(int *numbers, int count, compare_cb cmp)
{
	int i = 0;
	int j = 0;
	int *target = malloc(count * sizeof(int));

	int temp_low = 0;
	int temp_high = 0;
	int min_idx = 0;

	if (!target)
		die("Memory error,");

	memcpy(target, numbers, count * sizeof(int));

	for (i = 0; i < count; i++) {

		min_idx = i;
		for (j = i+1; j < count; j++) {
			if(cmp(target[min_idx], target[j]) > 0) {
				min_idx = j;
			}
		}

		temp_low = target[min_idx];  //make copy of the min value
		temp_high = target[i];       //make copy of the first pos
		target[i] = temp_low;  		 //set the position to the lowest value
		target[min_idx] = temp_high; //replace w/ first position
	}

	return target;
}

	
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	int *target = malloc(count * sizeof(int));

	if(!target)
		die("Memory error.");

	memcpy(target, numbers, count * sizeof(int));

	for (i = 0; i < count; i++) {
		for (j = 0; j < count - 1; j++) {
			// printf("i: %d\tj: %d\t", i,j);
			// printf("target: j: %d\t target: j+1 %d\t", target[j], target[j+1]);
			if(cmp(target[j], target[j+1]) > 0) {
				temp = target[j+1];
				// printf("temp: %d\t", temp);
				target[j+1] = target[j];
				// printf("target: j+1: %d\t", target[j+1]);
				target[j] = temp;
				// printf("target_j: %d\n", target[j]);
			} 
		}
	}

	return target;
}

int sorted_order(int a, int b)
{
	return a - b;
}

int reverse_order(int a, int b)
{
	return b - a;
}

int strange_order(int a, int b)
{
	if (a == 0 || b == 0) {
		return 0;
	} else {
		return a % b;
	}
}


void test_sorting(int *numbers, int count, compare_cb cmp)
{
	int i = 0;
	int *sorted = bubble_sort(numbers, count, cmp);
	// int *selected = selection_sort(numbers, count, cmp);

	if(!sorted)
		die("Failed to sort as requested.");

	// if(!selected)
	// 	die("Failed to sort as requested.");

	// printf("bubble sort: \n");
	for (i = 0; i < count; i++) {
		printf("%d", sorted[i]);
	}
	printf("\n");

	// printf("selected sort: \n");
	// for (i = 0; i < count; i++) {
	// 	printf("%d", selected[i]);
	// }
	// printf("\n");

	free(sorted);
	// free(selected);
}

void dump(compare_cb cmp)
{
	int i = 0;

	check(cmp != NULL, "Invalid function ptr to dump.");
	unsigned char *data = (unsigned char *)cmp;

	for(i = 0; i < 25; i++)  {

     	printf("%02x:", data[i]);

	}

	printf("\n");

error:
	printf("\n");

}

// void destroy(compare_cb cmp)
// {
// 	int i = 0;

// 	unsigned char *data = (unsigned char *)cmp;
// 	debug("data is %p:%s", data, data);

// 	for(i = 0; i < 25; i++) {
// 		debug("assign %d to data at %d", i, i);
//      	data[i] = i;
// 	}

// 	printf("\n");
// }


int main(int argc, char *argv[])
{
	if (argc < 2) die("USAGE: ex18 4 3 1 5 6");

	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;

	int *numbers = malloc(count * sizeof(int));

	if (!numbers) die("Memory error.");

	for (i = 0; i < count; i++) {
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);

	free(numbers);

	printf("SORTED:");
	dump(numbers);

	// debug("calling destroy with %p", sorted_order);
	// destroy(sorted_order);

	// printf("REVERSE:");
	// dump(reverse_order);

	return 0;
}

















