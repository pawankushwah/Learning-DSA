#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// User Defined Functions on Array
int *getArrData(int *arr, int arrSize);
int *printArrData(int *arr, int arrSize);
int *reverse(int *arr, int arrSize);
int *rotate(int *arr, int arrSize, int approach, int place);

int main(void)
{
    int choice;
    int arr[5];
    int arrSize = sizeof(arr)/sizeof(int);
    printf("First of all Enter your array data to perform operation\n");
    getArrData(arr,arrSize);

    // variable for rotating the array
    short side, approach, place;
    
    while(choice){
        printf("\nEnter your Choose:\n1. Reverse\n2. Print Array Data\n3. Rotate the Array\n0. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            reverse(arr, arrSize);
            printArrData(arr,arrSize);
            printf("Reversed String\n");
            break;
        
        case 2:
            printf("Printing Array Data\n");
            printArrData(arr, arrSize);
            printf("\n");
            break;
        
        case 3:
            sideChoice:
            printf("Enter the side of rotating the array\n1. Left\n2. Right\n");
            scanf("%d",&side);

            if(side != 1 && side != 2){
                printf("Invalid Choice!");
                goto sideChoice;
            }

            approachChoice:
            printf("Enter the Approach \n1. Using Temperary array\n2. Rotate one by one\n3. A juggling Algorithm\n4. Using Collection module\n");
            scanf("%d",&approach);
            
            if(approach != 1 && approach != 2 && approach != 3 && approach != 4){
                printf("Invalid Choice!");
                goto approachChoice;
            }

            placeChoice:
            printf("Enter the place you want to rotate\n");
            scanf("%d",&place);
            
            // if(!isnum(place)){
            //     printf("Invalid Choice!");
            //     goto placeChoice;
            // }

            rotate(arr, arrSize, approach, place);
            printArrData(arr, arrSize);
            printf("\n");
            break;
        
        case 0:
            exit(0);
            break;
        
        default:
            printf("Invalid Choice!");
            break;
        }

    }

    return 0;
}

int *getArrData(int *arr, int arrSize){
    printf("Enter your Array Values\n");
    for(int i = 0; i < arrSize; i++){
        printf("%d value:\t", i+1);
        scanf("%d", (arr + i));
    }
    return arr;
}

int *printArrData(int *arr, int arrSize){
    for(int i = 0; i < arrSize; i++){
        printf("%d ", *(arr + i));
    }
    return arr;
}

int *reverse(int *arr, int arrSize){
    // Unoptimized way to reverse integer array
    // int temp;
    // for(int i = 0; i < arrSize/2; i++){
    //     temp = arr[i];
    //     arr[i] = arr[arrSize - i - 1];
    //     arr[arrSize - i - 1] = temp;
    // }
    // return arr;

    // Optimized Way with help of pointer algebra
    int temp;
    for(int i = 0; i < arrSize/2; i++){
        temp = *(arr + i);
        *(arr+i) = *(arr + arrSize - i - 1);
        *(arr + arrSize - i - 1) = temp;
    }
    return arr;
}

int *rotate(int *arr, int arrSize, int approach, int place){
    int temp[arrSize], j = 0;

    switch(approach)
    {
    case 1:
        // By temporary array method
        for(int i = place - 1; i < arrSize; i++){
            temp[j] = *(arr+i);
            j++;
        }
        for (int i = 0; i < place; i++)
        {
            temp[j] = *(arr+i);
            j++;
        }
        for (int i = 0; i < arrSize; i++)
        {
            *(arr+i) = temp[i];
        }
        break;
    
    default:
        break;
    }
    return arr;
}