//String handleing

#include <string.h>
#include <stdio.h>

int main()
{
    char name[100];
    int i;
    printf("Enetr a name::\n");
    scanf("%[^\n]s", &name);
    //printf("The name you entered is ::%s\n", name);
    i = 0;
    while (name[i] != '\0')
    {
        printf("%c", name[i]);
        i++;
    }

    return 0;
}