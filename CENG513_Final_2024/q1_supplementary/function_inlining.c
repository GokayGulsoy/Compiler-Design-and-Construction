#include <stdlib.h>
#include <stdio.h>

// simple function to sum
// two integer values
int sum(int a,int b) {
	int c = a + b;
	return c;
}

int main() {
	int a = 15;
	int b = 20;
	int c = 25;

	int e = sum(a,b) + c;	
	
	return 0;
}

