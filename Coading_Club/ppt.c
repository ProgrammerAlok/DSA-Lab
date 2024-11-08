/*
Your mother has given you Rs. X to buy pen, pencil and paper.  
You ask a shop keeper about the unit price of each of the materials. 
Find a the number of elements you can buy maximum with the Rs. Given to you.
*/

#include<stdio.h>

int main(){
    int pen , pencil, paper;
    int money , elements;
    printf("Enter the amount money given by my mom is = \n");
    scanf("%d", &money);
    printf("The unit price of pen is = \n");
    scanf("%d", &pen);
    printf("The unit price of pencil is = \n");
    scanf("%d", &pencil);
    printf("The unit price of paper is = \n");
    scanf("%d", &paper);
    int a = pen + pencil + paper;
    int b = (money/a);
    elements = b * 3;
    // printf("%d", elements);
    printf("The maximum number of elements you can buy with the money is = %d\n", elements);
    return 0;
}