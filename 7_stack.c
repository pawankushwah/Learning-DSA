#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void push(int *arr, int arrMaxSize, int *arrTop){
    if(*arrTop == arrMaxSize - 1){
        printf("Overflow! Max Stack size is 3\n");
    }else{
        int value;
        printf("Enter your Element for Pushing to stack: ");
        scanf("%d", &value);
        (*arrTop)++;
        arr[*arrTop] = value;
        printf("pushed Successfully");
    }
}

void pop(int *arr, int *arrTop){
    if(*arrTop == -1){
        printf("underflow!\n");
    }else{
        printf("Popped Element: %d\n", arr[*arrTop]);
        arr[*arrTop] = 0;
        (*arrTop)--;
        printf("Popped Successfully");
    }
}

void show(int *arr, int arrMaxSize, int *arrTop){
    if(*arrTop == -1){
        printf("Stack is Empty\n");
    }else{
        printf("\nStack Element\n");
        for(int i = *arrTop; i >= 0; i--){
            printf("%d\n",arr[i]);
        }
    }
}

void main(){
    int arrTop = -1;
    int arrMaxSize = 3;
    int arr[arrMaxSize];
    
    int choice;
    while(1){
        system("cls");
        printf("Enter your Choice\n");
        printf("1. Push\n2. Pop\n3. Show\n4. End\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                push(arr, arrMaxSize, &arrTop);
                break;
            case 2:
                pop(arr, &arrTop);
                break;
            case 3:
                show(arr, arrMaxSize, &arrTop);
                break;
            case 4:
                printf("Thanks For using\n");
                getch();
                exit(0);
        }
        getch();
    }
}