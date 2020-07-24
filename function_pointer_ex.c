#include <stdio.h>

/*
Function pointers:
Why ?: 

example: void (*pf)(int)
-*pf is the pointer to a function 
-void is the return type of that function
-int is the argument type of that function
-similiar to the structure of a function void pf(int)

you can point to the function using pf = &addXtoY



   */

typedef int (*ptrf)(int, int);


int addXtoY(int a, int b) {
        return a + b;
}

int main() {
        int (*pf)(int, int);
        pf = &addXtoY;
        int x = pf(2,3);

        ptrf p = &addXtoY;
        int x2 = (*p)(2, 3);
        
        printf("x: %d\n", x);
        printf("y: %d\n", x2);
        return 0;
}
                




