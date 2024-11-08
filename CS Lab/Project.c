#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>

char source_air_port[60], destination_air_port[60];
char email_id[50], mobile_number[15];
char f_location[200] = "E:\\PROGRAMMING\\C Programming\\Collage coading\\CS Lab\\Booking_Details\\";
FILE *fp_DomFlight, *fp_InterFlight, *fp_Input, *fp_Output;

struct customer
{
    char Name[50];
    char Passport[10];
    char Gender;
    int Age;
    char Aadhaar_number[15];
};

char * ConvertUppercase(char *b)
{
    int i;
    for (i = 0; b[i]; i++)
    {
        if (b[i] >= 'a' && b[i] <= 'z')
        {
            b[i] = b[i] - 32;
        }
    }
}

struct customer Customer_Details_Input()
{
    struct customer cust;
    printf("Enter name : ");
    strcpy(cust.Name, TakeStringInput(cust.Name, '65', '122'));
    fflush(stdin);
    printf("Enter Age : ");
    strcpy(cust.Age, TakeStringInput(cust.Age, '0', '9'));
    fflush(stdin);
    printf("Enter Gender : ");
    strcpy(cust.Gender, TakeStringInput(cust.Gender, '65', '122'));
    fflush(stdin);
    printf("Enter Aadhaar : ");
    strcpy(cust.Aadhaar_number, TakeStringInput(cust.Aadhaar_number, '0', '9'));
    
    fflush(stdin);
    printf("Enter Passport : ");
    scanf("%s", cust.Passport);
    return cust;
}

bool CheckInput(char *input, char lower, char upper, char *type)
{
    int size = strlen(input);
    int i = 0;
    if(type == array)
    for (i = 0; i < size; i++)
    {
        if (input[i] >= 'lower' && input[i] <= 'upper')
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

char *TakeStringInput(char *input, char lower, char upper, char *type)
{
    bool result;
    while (1)
    {
        fflush(stdin);
        fgets(input, sizeof(input), stdin);
        result = CheckInput(input, lower, upper);
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

char CheckOption(char a, char b)
{
    char n;
    while (1)
    {
        fflush(stdin);
        scanf("%c", &n);
        if (n >= a && n <= b)
        {
            break;
        }
        else
        {
            printf("**** Please Enter a Valid Input ****\n");
        }
    }
    return n;
}

char HomePage()
{
    printf(".....WELCOME TO AIR INDIA......\n");
    printf("PRESS \"1\" to book a ticket. \nPRESS \"2\" to cancel a booked ticket. \n");
    char n = CheckOption('1', '3');
    return n;
}

char ChooseDomORInter()
{
    int n;
    printf("PRESS \"1\" For Domestic Booking. \nPRESS \"2\" For International Booking. \n");
    n = CheckOption('1', '2');
    return n;
}

char *Input_Email(char *email_id)
{
    // email_id = (char *)malloc(30 * (sizeof(char)));
    strcpy(email_id, TakeStringInput(email_id, '46', '122'));
}

void Mobile(char *mobile_number)
{
    // mobile_number = (char *)malloc(15 * (sizeof(char)));
    strcpy(mobile_number, TakeStringInput(mobile_number, '0', '9'));
}

void CancelTicket()
{
    fflush(stdin);
    printf("Please enter your Email ID : \n-> ");
    // scanf("%[^\n]s", email_id);
    strcpy(email_id, TakeStringInput(email_id, '46', '122'));
    strcat(f_location, email_id);
    strcat(f_location, ".txt");
    if (remove(f_location) == 0)
    {
        printf("********TICKET ***** CANCEL ****** SUCCESSFUL **********\n");
        printf("\n********** THANK YOU ******* VISIT ***** AGAIN **********\n");
    }
    else
        printf("********TICKET ***** CANCEL ****** FAILED **********\n");
    fflush(stdin);
}

void BookingStatus(FILE *fp, char ch)
{
    fflush(stdin);
    printf("Please enter your Email ID : \n-> ");
    // scanf("%[^\n]s", email_id);
    strcpy(email_id, TakeStringInput(email_id, '46', '122'));

    strcat(f_location, email_id);
    strcat(f_location, ".txt");
    fp = fopen(f_location, "r");
    printf("\n");
    printf("==========================================================================");
    printf("\n");
    if (fp == NULL)
    {
        printf("Your booking data is not found please check your \"Email ID\".\n");
    }
    else
    {
        ch = fgetc(fp);
        while (!feof(fp))
        {
            printf("%c", ch);
            ch = fgetc(fp);
        }
    }
}

void BookTicket()
{
    Email(email_id);
    fflush(stdin);
    printf("Please enter your Email ID : \n-> ");
    // scanf("%[^\n]s", email_id);
    strcpy(email_id, TakeStringInput(email_id, '46', '122'));
    strcat(f_location, email_id);
    strcat(f_location, ".txt");
}

int main()
{
    char m, n, ch;
    printf("Code is in process....\n");
    n = HomePage();
    switch (n)
    {

    case '1':
        /* code for flight ticket booking */
        m = ChooseDomORInter(); // --> choose domestic or international.
        switch (m)
        {

        case '1':
            /* code for domestic ticket */
            BookTicket();
            break;

        case '2':
            /* code for international ticket */
            break;
        }

        break;

    case '2':
        /* code for check ticket booking status */
        break;

    case '3':
        /* code for cancel a ticket */
        CancelTicket();
        break;
    }
    return 0;
}