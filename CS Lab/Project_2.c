#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>

typedef struct customer
{
   char name[50];
   char passport[10];
   char sex;
   int age;
   char aadhaar_number[15];
} cust;

int main()
{
   char A = '1';

   while (A != 'b')
   {
      char source_air_port[60];
      char destination_air_port[60];
      char email_id[50], ch, y, n;
      // char f_location[200] = "E:\\PROGRAMMING\\C Programming\\Collage coading\\CS Lab\\Booking_Details\\";   //-> **use for customise location path**
      char f_location[200] = "";
      char mobile_number[12];
      int a, b, i, j, k;
      long long int d;
      cust c;
      FILE *fp;
      int x, z;

      //......Welcome Note......
      printf("\n\t\t:::::::::::::::::  WELCOME TO AIR INDIA :::::::::::::::::\n");
      do
      {
         printf("\n\t\t=================================================================================");
         printf("\n");
         printf("\n\t\t\t**NOTE : IF YOU FACE ANY PROBLEM PLEASE RE-RUN THE FILE**\n");
         printf("\t\t\t\t***** THANK YOU FOR TAKE OUR SERVICES *****\n");
         printf("\n\t\t\tPRESS \"1\" to book a ticket. \n\t\t\tPRESS \"2\" check your booked ticket. \n\t\t\tPRESS \"3\" to cancel ticket.\n\t\t\t-> ");
         scanf("%c", &n);
         if (n == '1' || n == '2' || n == '3')
         {
            switch (n)
            {
            case '1':

               // ** Email ID input **
               fflush(stdin);
               printf("\t\t\tPlease enter your Email ID : \n\t\t\t-> ");
               scanf("%[^\n]s", email_id);
               strcat(f_location, email_id);
               strcat(f_location, ".txt");
               fp = fopen(f_location, "w");
               printf("\n");
               fprintf(fp, "\nEmail ID is : %s\n", email_id);


               // ** Contact number input & also 10 digits check **
               do
               {
                  fflush(stdin);
                  printf("\t\t\tPlease enter your contact number : \n\t\t\t");
                  scanf("%[^\n]s", mobile_number);
                  if (strlen(mobile_number) != 10)
                  {
                     printf("\t\t\t****Please enter a valid mobile no****\n");
                  }
                  else
                  {
                     fprintf(fp, "Contact Number is : %s\n", mobile_number);
                     break;
                  }
               } while (1);

               // ** Departure Airport names message print **
               fflush(stdin);
               printf("\n\t\t\t1. Indira Gandhi International Airport - New Delhi.\n\t\t\t2. Rajiv Gandhi International Airport - Hyderabad.\n\t\t\t3. Bengaluru International Airport - Bengaluru.\n\t\t\t4. Chhatrapati Shivaji International Airport - Mumbai.\n\t\t\t5. Chennai International Airport - Chennai.\n\t\t\t6. Netaji Subhash International Airport - Kolkata.\n");

               // ** Departure Airport coose & also validity check **
               while (1)
               {
                  fflush(stdin);
                  printf("\n\t\t\tPlease choose departure airport (1 to 6)[eg..1,2] : \n\t\t\t-> ");
                  scanf("%d", &x);
                  switch (x)
                  {
                  case 1:
                     fprintf(fp, "\nDeparture airport is : Indira Gandhi International Airport - New Delhi.\n");
                     break;
                  case 2:
                     fprintf(fp, "\nDeparture airport is : Rajiv Gandhi International Airport - Hyderabad.\n");
                     break;
                  case 3:
                     fprintf(fp, "\nDeparture airport is : Bengaluru International Airport - Bengaluru.\n");
                     break;
                  case 4:
                     fprintf(fp, "\nDeparture airport is : Chhatrapati Shivaji International Airport - Mumbai.\n");
                     break;
                  case 5:
                     fprintf(fp, "\nDeparture airport is : Chennai International Airport - Chennai.\n");
                     break;
                  case 6:
                     fprintf(fp, "\nDeparture airport is : Netaji Subhash International Airport - Kolkata.\n");
                     break;

                  default:
                     printf("\t\t\t******** Please choose a valid Airport no ********\n\t\t\t");
                     break;
                  }
                  if (x > 0 && x < 7)
                     break;
               }
               fflush(stdin);
               printf("\n");

               // ** Departure Airport names message print **
               printf("\n\t\t\t1. Indira Gandhi International Airport - New Delhi\n\t\t\t2. Rajiv Gandhi International Airport - Hyderabad.\n\t\t\t3. Bengaluru International Airport - Bengaluru.\n\t\t\t4. Chhatrapati Shivaji International Airport - Mumbai.\n\t\t\t5. Chennai International Airport - Chennai.\n\t\t\t6. Netaji Subhash International Airport.\n");

               // ** Departure Airport coose & also validity check **
               fflush(stdin);
               while (z < 1 || z > 6)
               {
                  printf("\n\t\t\tPlease choose destination Airport (1 to 6) : \n\t\t\t-> ");
                  scanf("%d", &z);
                  switch (z)
                  {
                  case 1:
                     fprintf(fp, "\nDestination airport is : Indira Gandhi International Airport - New Delhi.\n");
                     break;
                  case 2:
                     fprintf(fp, "\nDestination airport is : Rajiv Gandhi International Airport - Hyderabad.\n");
                     break;
                  case 3:
                     fprintf(fp, "\nDestination airport is : Bengaluru International Airport - Bengaluru.\n");
                     break;
                  case 4:
                     fprintf(fp, "\nDestination airport is : Chhatrapati Shivaji International Airport - Mumbai.\n");
                     break;
                  case 5:
                     fprintf(fp, "\nDestination airport is : Chennai International Airport - Chennai.\n");
                     break;
                  case 6:
                     fprintf(fp, "\nDestination airport is : Netaji Subhash International Airport - Kolkata.\n");
                     break;

                  default:
                     printf("\t\t\t******** Please choose a valid Airport no ********\n\t\t\t");
                     break;
                  }
               }

               fflush(stdin);


               //** Passenger details input **
               do
               {
                  printf("\t\t\tHow many people you are travel (1-8) : \n\t\t\t-> ");
                  scanf("%d", &a);
                  if (a > 0 && a < 9)
                  {
                     for (i = 0; i < a; i++)
                     {
                        fprintf(fp, "\nPassenger %d details : \n", i + 1);
                        printf("\t\t\tEnter passenger %d details : \n", i + 1);

                        fflush(stdin);
                        printf("\t\t\tEnter Name : ");
                        scanf("%[^\n]s", c.name);
                        fprintf(fp, "Name : %s\n", c.name);

                        fflush(stdin);
                        do
                        {
                           fflush(stdin);
                           printf("\t\t\tEnter Sex[m/f] : ");
                           scanf("\n");
                           scanf("%c", &y);
                           switch (y)
                           {
                           case 'm':
                              fprintf(fp, "Sex : Male\n");
                              break;
                           case 'f':
                              fprintf(fp, "Sex : Female\n");
                              break;

                           default:
                              printf("\t\t\t**** Please enter a correct alphabet ****\n");
                              break;
                           }
                           if (y == 'm' || y == 'f')
                           {
                              break;
                           }
                        } while (1);

                        fflush(stdin);
                        b = 1;
                        while (b == 1)
                        {
                           printf("\t\t\tEnter Age : ");
                           scanf("%d", &c.age);
                           if (c.age < 1 || c.age > 80)
                           {
                              printf("\t\t\t******Please enter a valid age******\n");
                           }
                           else
                           {
                              fprintf(fp, "age : %d\n", c.age);
                              break;
                           }
                        }

                        fflush(stdin);
                        b = 1;
                        while (b == 1)
                        {
                           printf("\t\t\tEnter Aadhaar ID : ");
                           scanf("%[^\n]s", c.aadhaar_number);

                           if (strlen(c.aadhaar_number) != 12)
                           {
                              printf("\t\t\t****Please enter a valid aadhaar no****\n");
                           }
                           else
                           {
                              fprintf(fp, "Aadhaar ID : %s\n", c.aadhaar_number);
                              break;
                           }
                           fflush(stdin);
                        }

                        fflush(stdin);
                        b = 1;
                        while (b == 1)
                        {
                           fflush(stdin);
                           printf("\t\t\tEnter Passport Number : ");
                           scanf("%[^\n]s", c.passport);
                           if (strlen(c.passport) != 8)
                           {
                              printf("\t\t\t**** Please enter a valid Passport ID ****\n");
                           }
                           else
                           {
                              fprintf(fp, "Passport Number : %s\n", c.passport);
                              break;
                           }
                        }
                     }

                     printf("\n\n\t\t\t*********** TICKET ** BOOKING ** SUCCESSFUL ************\n");
                     printf("\n\t\t\t********** THANK YOU ******* VISIT ***** AGAIN **********\n");
                     break;
                  }
                  else
                  {
                     printf("\t\t\t******** Please enter a valid number of passenger between 1 to 8 *********\n");
                  }
                  fflush(stdin);
                  fclose(fp);
               } while (a < 1 || a > 8);
               fclose(fp);

               break;

            // ** Booking details check **
            case '2':
               fflush(stdin);
               printf("\n\t\t\tPlease enter your Email ID : \n\t\t\t-> ");
               scanf("%[^\n]s", email_id);
               strcat(f_location, email_id);
               strcat(f_location, ".txt");
               fp = fopen(f_location, "r");
               printf("\n\t\t\t==========================================================================\n");
               if (fp == NULL)
               {
                  printf("\n\t\t\t**** Your booking data is not found please check your \"Email ID\" ****.\n\t\t\t**** Press any key to continue ****\n");
                  printf("\n\t\t\t==========================================================================\n");
                  getch();
               }
               else
               {
                  printf("\n\t\t\t**** YOUR BOOKING HISTORY IS ****\n");
                  ch = fgetc(fp);
                  while (!feof(fp))
                  {
                     printf("%c", ch);
                     ch = fgetc(fp);
                  }
               }
               fclose(fp);
               break;

            // ** Cancel booked ticket **
            case '3':
               fflush(stdin);
               printf("\t\t\tPlease enter your Email ID : \n\t\t\t-> ");
               scanf("%[^\n]s", email_id);
               strcat(f_location, email_id);
               strcat(f_location, ".txt");

               if (remove(f_location) == 0)
               {
                  printf("\n\t\t\t********TICKET ***** CANCEL ****** SUCCESSFUL **********\n");
                  printf("\n\t\t\t********** THANK YOU ******* VISIT ***** AGAIN **********\n");
                  getch();
               }
               else
               {
                  printf("\t\t\t********TICKET ***** CANCEL ****** FAILED **********\n");
                  getch();
               }
               fflush(stdin);
               fclose(fp);
               break;
            }
            break;
         }
         else
            printf("\n\t\t\t****** Please enter a valid number ******\n");

         fflush(stdin);
      } while (1);

      fflush(stdin);
      fclose(fp);
      printf("\n\t\t\t==========================================================================\n");

      printf("\n\t\t\tPress \"b\" to exit.\n");
      printf("\t\t\tPress any key to continue.\n\t\t\t-> ");
      scanf("%c", &A);
   }

   getch();
   return 0;
}