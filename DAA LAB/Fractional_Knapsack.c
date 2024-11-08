#include<stdio.h>
#include<stdlib.h>
typedef struct Object{ double profit, weight, pw_ratio; } object;
int main()
{
    int n, i, j;
    double m, profit = 0;

    printf("Enter the capacity of Knapsack :: ");
    scanf("%lf", &m);

    printf("Enter how many object :: ");
    scanf("%d", &n);

    object *obj = (object *)calloc(n, sizeof(object));

    for(i=0; i<n; i++) {
        printf("Enter the weight of object%d :: ", i+1);
        scanf("%lf", &(obj+i)->weight);

        printf("Enter the profit of object%d :: ", i+1);
        scanf("%lf", &(obj+i)->profit);

        (obj+i)->pw_ratio = (obj+i)->profit / (obj+i)->weight;
    }

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if((obj+i)->pw_ratio<(obj+i+1)->pw_ratio) {
                object temp = obj[i];
                obj[i] = obj[i+1];
                obj[i+1] = temp;
            }
        }
    }

    for(i=0; i<n; i++) {
        if(m>0 && (obj+i)->weight <= m) {
            profit += (obj+i)->profit;
            m -= (obj+i)->weight;
        }
    }

    if(m>0) {
        profit += (obj+i)->pw_ratio * m;
    }

    printf("Max Profit :: %lf", profit);

    return 0;
}
