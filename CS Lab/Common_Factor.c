#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a, b, H;
    printf("Enter the first number: \n");
    scanf("%d",&a);
    printf("Enter the second number: \n");
    scanf("%d",&b);
    for(H=a<b?a:b ; H>=1 ; H--){
        if(a%H==0 && b%H==0){
            printf("%d ", H);
        }
        break;
    }
    return 0;
}