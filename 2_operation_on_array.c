#include <stdio.h>

void traversal(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int insertion(int *arr, int *size, int capacity, int element, int index)
{
    int arrSize = *size;
    if (arrSize >= capacity)
        return -1;
    else
    {
        for (int i = arrSize; i > index; i--)
            arr[i] = arr[i - 1];

        arr[index] = element;
        *size += 1;
        return 1;
    }
}

void deletation(int *arr, int *size, int capacity, int index){
    int arrSize = *size;

    for (int i = index; i < arrSize - 1; i++)
        arr[i] = arr[i + 1];

    arr[arrSize - 1] = 0;
    *size -= 1;
}

int main(void)
{
    int capacity = 100;
    int array[100] = {1, 2, 3, 5, 6};
    int size = 5;
    traversal(array, size);

    (insertion(array, &size, capacity, 100, 3) == 1) ? printf("Insertion Successful") : printf("Insertion unsuccessful");
    printf("\n");

    traversal(array, size);

    deletation(array, &size, capacity, 3);
    
    traversal(array, size);
    return 0;
}