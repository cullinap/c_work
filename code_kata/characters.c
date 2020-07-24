#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {

    char s[100];
    char str[100];

    scanf("%s\n", s);
    scanf("%[^\n]%*c", str);
    printf("%s\n", s);
    printf("You entered: %s\n", str);

    return 0;
}


