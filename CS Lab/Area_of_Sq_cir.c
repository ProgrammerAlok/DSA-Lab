// 

#include<stdio.h>
#include<math.h>

int main()
{
    int s_d;
    printf("Enter a number: \n");
    scanf("%d", &s_d);
    float AreaCircle = 3.14*s_d*s_d;
    float AreaSquare = s_d*s_d;
    if(AreaCircle>AreaSquare){
        printf("As the area of circle is %f & the area of square is %f. So the area of circle is greater\n", AreaCircle, AreaSquare);
    }
    else{
        printf("As the area of circle is %f & the area of square is %f. So the area of square is greater\n", AreaCircle, AreaSquare);
    }
    return 0;
}