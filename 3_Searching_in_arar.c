#include <stdio.h>

int linearSearch(int *arr, int arrSize, int element)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}

int binarySearch(int *arr, int arrSize, int element)
{
    int a = 0, b = arrSize - 1;
    int mid;

    if (arr[a] == element)
        return 0;
    if (arr[b] == element)
        return arrSize - 1;

    while (a <= b)
    {
        mid = (a + b) / 2;
        if (arr[mid] == element)
            return mid;
        if (arr[mid] < element)
            a = mid + 1;
        else
            b = mid - 1;
    }
    return -1;
}

int main(void)
{
    int arr[10];
    int arrSize = sizeof(arr)/sizeof(int);
    int element;

    for (int i = 0; i < 9; i++)
        scanf("%d", &arr[i]);

    printf("Enter the you want to Search: \t");
    scanf("%d", &element);

    int result = binarySearch(arr, arrSize, element);
    (result != -1) ? printf("number is available at %d",result) : printf("Not Found");
    return 0;
}