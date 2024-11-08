#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int num;
    printf("Enter a number: \n");
    scanf("%d", &num);
    for(int i=1; i<=num ; i++){
        if(num%i==0){
            printf("%d ", i);
        }
    }
    return 0;
}