#include <stdio.h>

void doNothing() {
    int i = 10; // This assignment is dead code
}

int main() {
    doNothing(); // The call to doNothing is effectively dead code
    
    int a = 10;
    int b = 20;
    int result = a + b;
    printf("Result: %d\n", result);

    int unused = 100; // This variable is never used
    
    return 0;
}

