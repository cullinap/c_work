#include <stdio.h>

typedef struct {
	int feet;
	int inch;
} distance;


int main() {
	distance mydistance = {10, 7};
	printf("%d \n %d\n", mydistance.feet, mydistance.inch);
}


struct Distance {
	int feet;
	int inch;
};

int main()
{
	struct Distance dist1;

	dist1.feet = 10;
	dist1.inch = 7;
	printf("%d \n %d \n", dist1.feet, dist1.inch);

	return 0;
}


