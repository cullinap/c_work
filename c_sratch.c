#include <stdio.h>

void print(int n) {
        if (n >= 6) {
                printf("hello world");
        } else {
                printf("fuck you");
        }
    
}

void helloworld(void (*f) ()) {
        f();
}

int main() {
        print(6); 
        print(2);

        return 0;
}





