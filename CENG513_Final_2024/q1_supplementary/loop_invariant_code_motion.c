#include <stdlib.h>
#include <stdio.h>

int main() {
	int a = 10;
	int b = 20;
		
	int i = 0;
	while (i < 5) {
		int c = a + b; // loop invariant code
		printf("Value of a*b is: %d",a*b);
		i++;
	}

	return 0;
}








