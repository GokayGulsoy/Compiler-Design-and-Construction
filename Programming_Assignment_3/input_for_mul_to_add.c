//======================================================
// FILE: 
//  input_for_mul_to_add.c
//  
// DESCRIPTION: 
//  Sample input file for the MulToAdd pass
//
//======================================================

#include <stdio.h> 
#include <stdlib.h>

int main(int argc,char *argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);

    int e = 2 * a;
    int f = 2 * b;
    int g = 2 * c;
    int h = 2 * d;
    
    return e + f + g + h;
}
