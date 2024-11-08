#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int roll_num, temp, rem;
    printf("Please enter a four digit number in between 1112 to 9999: \n");
    scanf("%d", &roll_num);
    if(roll_num<=1111 || roll_num>9999)
    {
        printf("!!Plesse enter a four digit number in between 1112 to 9999!!");
    }
    else
    {
        int rev_num=0;
        temp=roll_num;
        for( ;temp>0; )
        {
            rem=temp%10;
            rev_num=rev_num*10+rem;
        }
        temp=temp/10;
        printf("The reverse number is: %d\n", rev_num);
    }
    return 0;
}


// 3
/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    float area_floor, area_tiles, tiles_length, tiles_breadth, floor_length, floor_breadth, tiles_num, tiles_pack;
    printf("Enter the length and breadth of floor respectively: \n");
    scanf("%f %f", &floor_length, &floor_breadth);
    printf("Enter the length and breadth of tiles respectively: \n");
    scanf("%f %f", &tiles_length, &tiles_breadth);

    area_floor=floor_length*floor_breadth;
    area_tiles=tiles_length*tiles_breadth;
    tiles_num=area_floor/area_tiles;
    tiles_pack=tiles_num/4;

    if(tiles_length<=0 || tiles_breadth<=0 || floor_length<=0 || floor_breadth<=0)
    {
        printf("Please inter a valid input.\n");
    }
    else if (area_floor<area_tiles)
    {
        printf("The pack of tiles required is: 1\n");
    }
    
    else
    {
        
        printf("The pack of tiles required to fill the floor is: %.0f\n", tiles_pack);
    }
    return 0;
}

*/