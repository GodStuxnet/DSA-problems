#include <stdio.h>
#include <limits.h>

void thirdLargest(int arr[],int arr_size)
{
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    if (arr_size < 3) { printf("Invalid Input"); return; }
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] > first) { third = second; second = first; first = arr[i]; }
        else if (arr[i] > second && arr[i] != first) { third = second; second = arr[i]; }
        else if (arr[i] > third && arr[i] != second && arr[i] != first) third = arr[i];
    }
    if (third == INT_MIN) printf("Invalid Input");
    else printf("The third Largest element is %d", third);
}

int main()
{
    int n, arr[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    thirdLargest(arr, n);
    return 0;
}

