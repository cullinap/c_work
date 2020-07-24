#include <stdio.h> //header file for standard input output printf
#include <assert.h> //header file that defines assert
#include <stdlib.h> //has malloc in it, NULL
#include <string.h> //NULL, 

// define variables inside 
//struct to assign multiple variables to a name
struct Person {
	char *name; //create a pointer and point with it somewhere later
	int age; //variable type int named age
	int height; //variable type int named height
	int weight; //variable type int name weight
};

//function returns a pointer to a struct Person
struct Person *Person_create(char *name, int age, int height, int weight)

{
	struct Person *who = malloc(sizeof(struct Person)); //point to struct person and give access to a piece of memory the size of struct Person
	assert(who != NULL); //check that malloc did not return a NULL invalid pointer

	who->name = strdup(name); //initialize the name field of struct person. strdup copies the name string
	who->age = age; //initialize the age field of struct person
	who->height = height; //intialize the height field of struct person
	who->weight = weight; //initialize the weight field of struct person

	return who; 

	//whoe recreates the struct person and fills in the fields
}

//need to destroy a function once created
void Person_destroy(struct Person *who)
{
	assert(who != NULL); //check to make sure not getting bad input

	free(who->name); //free memory from string name
	free(who); //free memory from rest of struct
}

//print out people takes struct person as argument
void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name); //print each line
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}


//main function
int main(int argc, char *argv[])
{
	//make two people structures
	//create a pointer joe and piont to a struct
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);

	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	// print them out and where they are in memory
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);

	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	// make everyone age 20 years and print them again
	//using joe instead of who to access the variables in 
	//struct. To get to a variable in a struct you just go
	//struct name --> variable = value
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	// destroy them both so we clean up 
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}

















