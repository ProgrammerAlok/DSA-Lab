#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char Mobile[12], Email[30], Input;

struct customer
{
    char Name[50];
    char Passport[10];
    char Gender;
    int Age;
    char Aadhaar_number[15];
};

struct customer Customer_Details_Input()
{
    struct customer cust;
    printf("Enter name : ");
    scanf("%s", cust.Name);
    fflush(stdin);
    printf("Enter age : ");
    fgets(cust.Age, sizeof(cust.Age), stdin);
    // scanf("%s", s.st_name);
    fflush(stdin);
    printf("Enter gender : ");
    scanf("%s", cust.Gender);
    fflush(stdin);
    printf("Enter Aadhaar : ");
    scanf("%s", cust.Aadhaar_number);
    fflush(stdin);
    printf("Enter Passport : ");
    scanf("%s", cust.Passport);
    return cust;
}

char Welcome_note(char *a)
{
    while (1)
    {
        fflush(stdin);
        printf("\n:::::::::::::::::  WELCOME TO AIR INDIA :::::::::::::::::\n");
        printf("\n=================================================================================");
        printf("\n");
        printf("\n**NOTE : IF YOU FACE ANY PROBLEM PLEASE RE-RUN THE FILE**\n");
        printf("***** THANK YOU FOR TAKE OUR SERVICES *****\n");
        printf("\nPRESS \"1\" to book a ticket. \nPRESS \"2\" check your booked ticket. \nPRESS \"3\" to canceal ticket.\n-> ");
        scanf("%c", a);
        if (Input > 48 && Input < 52)
        {
            break;
        }
        else
            printf("\n*** Please enter a valid Input ***\n");
    }
    return a;
}

char Input_Mobile(char Mobile[])
{
    while (1)
    {
        fflush(stdin);
        printf("Enter your Mobile Number : \n");
        scanf("%[^\n]s", Mobile);
        if (strlen(Mobile) != 10)
        {
            printf("\n**** Please enter a valid Number ****\n");
        }
        else
        {
            int i;
            for (i = 0; i < strlen(Mobile); i++)
            {
                if (Mobile[i] > 47 && Mobile[i] < 58)
                    ;
            }
            if (i == 10)
            {
                return Mobile;
            }
            else
            {
                printf("\n**** Please enter a valid Number ****\n");
            }
        }
    }
}

char Input_Email(char Email)
{
}

int main()
{
    // Welcome_note(&Input);

    // Input_Email(&Email);

    Input_Mobile(Mobile);

    return 0;
}