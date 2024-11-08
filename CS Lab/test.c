#include<stdio.h>
#include<stdbool.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


bool CheckInput(char *input, char lower, char upper)
{
    int size = strlen(input);
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (input[i] >= lower && input[i] <= upper)
            ;
        else
            break;
    }
    if (i == size)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// char input[100];
char * TakeStringInput(char *input)
{
    
    bool result;
    while (1)
    {
        fflush(stdin);
        // fgets(input, sizeof(input), stdin);
        scanf("%[^\n]s", input);
        result = CheckInput(input, '0', '9');
        if (result == true)
        {
            break;
        }
        else
        {
            printf("*****Enter a valid input***** \n->");
        }
    }
    return input;
}

int main()
{

    char a[100];
    printf("Enter a string :  ");
    scanf("%[^\n]s", a);
    switch (*a)
    {
    case 'alok':
        printf("alok");
        break;
    case 'paul':
        printf("paul");
        break;
    
    default:
        break;
    }
    // scanf("%s", a);
    // int b = atoi(a);
    // printf("%d", b);
}