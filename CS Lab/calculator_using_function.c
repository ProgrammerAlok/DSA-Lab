// Make a calculator which works + - x / pow .Using function and switch case.

#include <stdio.h>
#include <math.h>

float add(float a, float b)
{
    return (a + b);
}

float subtraction(float a, float b)
{
    return (a - b);
}

float division(float a, float b)
{
    return (a / b);
}

float multipication(float a, float b)
{
    return (a * b);
}

float power(float a, float b)
{
    return (pow(a, b));
}

float input(float *a, float *b)
{
    printf("Enter two number: \n");
    scanf("%f %f", a, b);
}

int main()
{
    int n;
    float a, b;
    printf("=======================\nPress 1 for addition.\nPress 2 for subtraction.\nPress 3 for multipication.\nPress 4 for division.\nPress 5 for power.\n==============================\n--> ");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        input(&a, &b);
        printf("The addition of two number is: %f\n", add(a, b));
        break;

    case 2:
        input(&a, &b);
        printf("The subtraction of two number is: %f\n", subtraction(a, b));
        break;
    case 3:
        input(&a, &b);
        printf("The multipication of two number is: %f\n", multipication(a, b));
        break;
    case 4:
        printf("Enter the numerator and denominator trapectively: \n");
        scanf("%f %f", &a, &b);
        printf("The division of two number is: %f\n", division(a, b));
        break;
    case 5:
        printf("Enter the base and power respectively: \n");
        scanf("%f %f", &a, &b);
        printf("The expo of two number is: %f\n", power(a, b));
        break;

    default:
        printf("Please enter a valid number.\n");
        break;
    }

    return 0;
}