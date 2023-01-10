#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct arrMod
{
    int total_size;
    char used_size;
    int *ptr;
};

void createArr(struct arrMod *s, int tSize, int uSize){
    (*s).total_size = tSize;
    (*s).used_size = uSize;
    (*s).ptr = (int *) malloc(tSize * sizeof(int));    
}

void setVal(struct arrMod *s)
{
    for (int i = 0; i < (*s).used_size; i++)
    {
        int temp;
        printf("Enter the %d value: ", i);
        scanf("%d", &temp);
        (*s).ptr[i] = temp;
    }
}

void printfVal(struct arrMod *s)
{
    printf("Printing your arr\n");
    for (int i = 0; i < (*s).used_size; i++)
    {
        printf("%d ", (*s).ptr[i]);
    }
}

int main(void)
{
    struct arrMod arr;
    createArr(&arr, 10, 5);
    setVal(&arr);
    printfVal(&arr);
    return 0;
}