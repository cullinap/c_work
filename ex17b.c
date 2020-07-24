#include <stdio.h>
#include <string.h>

struct student
{
  int id;
  char name[20];
  float percentage;
};

void func(struct student *record)
{
  printf("Id is: %d \n", record->id);
  printf("Name is: %s \n", record->name);
  printf("Percent is: %f \n", record->percentage);

}

int main()
{
  struct student record;

  record.id=1;
  strcpy(record.name, "patrick");
  record.percentage = 86.5;

  func(&record);
  printf("record location: %p ", &record);
  return 0;

}

// typedef struct {
//   int id;
//   char name[20];
//   float percentage;
// } student;

// void func(student *record)
// {
//   printf("Id is: %d \n", record->id);
//   printf("Name is: %s \n", record->name);
//   printf("Percent is: %f \n", record->percentage);

// }

// int main()
// {
//   student record;

//   record.id=1;
//   strcpy(record.name, "patrick");
//   record.percentage = 86.5;

//   func(&record);
//   printf("record location: %p ", &record);
//   return 0;

// }




 
