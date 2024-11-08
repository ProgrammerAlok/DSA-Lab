#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void bubbleShort(int num[], int n)
{
    int i, j, temp;
    for(j=1;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(num[i]>num[i+1])
            {
                temp=num[i];
                num[i]=num[i+1];
                num[i+1]=temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("How many number you want to enter: \n");
    scanf("%d", &n);
    int num[n];
    int sum=0;

    for(int i=0; i<n;i++){
        printf("Enter the number f(%d): \n", i+1);
        scanf("%d", &num[i]);
    }
    
    for(int i=0; i<n;i++){
        sum=sum+num[i];
    }   
    printf("Sum: %d\n", sum);
    float avg=(float)sum/n;

    bubbleShort(num, n);

    printf("The maximum numbers: %d\n", num[n-1]);
    printf("The minimum numbers: %d\n", num[0]);
    printf("The average of %d numbers: %.2f\n", n, avg);
    
    return 0;
}