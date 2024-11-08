// Find the average of n number using arrays.

#include<stdio.h>
int main()
{
    float a[10], sum=0, avg;
    int i, n;
    printf("How many number: \n");
    scanf("%d", &n);
    printf("Enter the numbers:\n");
    for(i=0 ; i<n ; i++)
    {
        scanf("%f", &a[i]);
        sum += a[i];
    }
    avg = sum/n;
    printf("The average of the numbers is: %f", avg);
    return 0;
}