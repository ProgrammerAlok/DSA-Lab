// Write a C program to find the area of triangle where three sides are given.

#include<stdio.h>
#include<math.h>

int main(){
    float side1, side2, side3, area, s;
    printf("Enter the sides of a triangle = \n");
    scanf("%f %f %f", &side1, &side2, &side3);
    s = (side1+side2+side3)/2;
    area = sqrt(s*(s-side1)*(s-side2)*(s-side3));
    if(((side1+side2)>=side3) && ((side2+side3)>=side1) && ((side1+side3)>=side2)){
    // s = (side1+side2+side3)/2;
    // area = sqrt(s*(s-side1)*(s-side2)*(s-side3));   
    printf("The area of the triangle is = %.2f\n", area);
    }
    else{
        printf("The triangle is not possible\n");
    }
    //  printf("The area of the triangle is = %.2f\n", area);
    return 0;
}