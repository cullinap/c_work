#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	int size;
	printf("\nEnter the size of the array: ");
	scanf("%d", &size);
	
	int *A;
	A = (int*)malloc(size * sizeof(int));
	printf("\nEnter the values of the array: ");

	int i;
	for (i = 0; i < size; i++)
		scanf("%d", &A[i]);

	printf("\nThe values in the array are: \n");
	for (i = 0; i < size; i++)
		printf("%d\t", A[i]);
}


#define MAX_ROWS 2

typedef struct {
	int id;
	char name[20];
	float percent;
} Student;

void func(Student *record)
{
	printf("id: %d\nname %s\npercent %f\n", record->id, record->name, record->percent);
}

void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s", message);
	}
	exit(1);
}

struct Array {
	Student rows[MAX_ROWS];
};

int main(int argc, char *argv[])
{
	if (argc < 4)
		die("Args are <id> <name> <percent>");

	
	Student record;

	char *a = argv[1];
	char *b = argv[2];

	record.id = atoi(a);
	strcpy(record.name, "patrick");
	record.percent = atof(b);

	func(&record);
	printf("record location is: %p\n", &record);

	struct Array db;

	int i;
	for (i=0; i < MAX_ROWS; i++)
	{
		printf("Enter a name: ");
		scanf("%s", db.rows[i].name);
	}

	printf("\n");

	for (i=0; i < MAX_ROWS; i++)
	{
		printf("ID's are: %s\n", db.rows[i].name);
	}

	return 0;
}







