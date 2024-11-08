#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct student
{
    char name[50];
    int roll;
    float marks1;
    float marks2;
    float marks3;
    float total_marks;
};

int main()
{   
    int n, i, j;
    struct student *s;
    printf("Enter how many students: \n");
    scanf("%d", &n);
    s=(struct student *)malloc(n*sizeof(struct student));
    for(i=0 ; i<n ; i++)
    {
        int sum=0;
        printf("Enter the roll of student %d : \n", i+1);
        scanf("%d", (s+i)->roll);
        for(j=0 ; j<n ; j++)
        {
            printf("Marks%d : \n", j);
            if(j==0)
                scanf("%f", (s+i)->marks1);
            else if(j==1)
                scanf("%f", (s+i)->marks2);
            else if(j==2)
                scanf("%f", (s+i)->marks3);
            (s+i)->total_marks+=marks1;    
        }
    }

    return 0;
}