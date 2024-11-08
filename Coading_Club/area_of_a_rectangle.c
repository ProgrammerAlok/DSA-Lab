// Write a C program to compute the area of a rectangular floor,
// where you have to take the input of Length and Width of the floor.

#include<stdio.h>

int main(){
    float length, breadth;
    printf("Enter the length of the rectangle is = \n");
    scanf("%f", &length);
    printf("Enter the breadth of the rectangle is = \n");
    scanf("%f", &breadth);
    printf("The area of the rectangle is = %.2f\n", length*breadth);
    return 0;
}