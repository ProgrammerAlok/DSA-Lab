#include<stdio.h>

int main(){
    int a, b, c;
    int max;
    printf("enter the three number = ");
    scanf("%d %d %d", &a, &b, &c);

    // if(a<b && b<c){
    //     printf("imax = %d",c);
    // }
    // else if(c<b && b<a){
    //     printf("imax = %d",a);
    // }
    // else{
    //     printf("imax = %d",b);
    // }

    (a>b>c) ? printf("imax is = %d",a);
    (a<b<c) ? printf("imax is = %d",c);
    (b>a,b) ? printf("imax is = %d",b);


    return 0;
}