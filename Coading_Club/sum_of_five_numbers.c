// Write a C program to compute the summation of 5 numbers given as user input

#include<stdio.h>

int main(){
    float fnum1, fnum2, fnum3, fnum4, fnum5;
    printf("Enter five numbers = \n");
    scanf("%f %f %f %f %f", &fnum1, &fnum2, &fnum3, &fnum4, &fnum5);
    printf("The sum of five number is = %.2f\n", fnum1+fnum2+fnum3+fnum4+fnum5);
    return 0;
}