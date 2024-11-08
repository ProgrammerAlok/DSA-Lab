#include "bits/stdc++.h"
using namespace std;

/* -------------- BubbleSort  Start ------------------ */
void bubbleSort(int *arr, int size)
{
    int i(0), j(0);
    for(i=0; i<size; ++i){
        for(j=0; j<size-1-i; ++j){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
/* -------------- BubbleSort  End ------------------ */

/* -------------- QuickSort  Start ------------------ */
int partition(int *arr, int pivot, int low, int high)
{
    int i(low), j(low);
    while(i<=high) {
        if(arr[i] <= pivot) {
            swap(arr[i], arr[j]);
            ++i;
            ++j;
        }
        else ++i;
    }
    return j-1;
}
void quickSort(int *arr, int low, int high)
{
    if(low>high) return;
    int pivot = arr[high];
    int pivot_idx = partition(arr, pivot, low, high);
    quickSort(arr, low, pivot_idx - 1);
    quickSort(arr, pivot_idx + 1, high);
}
/* -------------- QuickSort  End ------------------ */

int main()
{
    int arr[] = { 9, 8, 1, 3, 6, 20, 1, 3, 6 };
    int n = sizeof(arr) / sizeof(int);

    // cout << partition(arr, 3, 0, n-1) << "\n";

    // quickSort(arr, 0, n-1); 
    bubbleSort(arr, n); 

    for(auto it : arr) cout << it << " ";

    

    return 0;
}