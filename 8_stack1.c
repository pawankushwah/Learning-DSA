#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Stack{
    int top;
    int *ptr;
    int size;
};

int push(struct Stack *, int), pop(struct Stack *), peep(struct Stack *, int), show(struct Stack *);

int beginStack(struct Stack *stack, int s){
    stack->top = -1;
    stack->size = s;
    stack->ptr = (int *)malloc(s*sizeof(int));
}

void main(){
    struct Stack *s1 = (struct Stack *)malloc(sizeof(struct Stack));
    int size, choice, result;
    int userIndex;
    int data;
    system("cls");
    printf("lets create a stack\n");
    printf("Enter the size of stack you want to create\n");
    scanf("%d",&size);
    beginStack(s1, size);
    
    while(1){
        system("cls");
        printf("lets do some operation on stack\n1. push\n2. pop\n3. peep\n4.show\n5.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter your data to put into the stack: ");
                scanf(" %d", &data);
                result = push(s1, data);
                if(result == -1) printf("Unable to push Reason: stack is full\n");
                else printf("pushed successfully");
                break;

            case 2:
                result = pop(s1);
                if(result < 0){
                    printf("unable to Pop the value because stack is empty\n");
                }else
                    printf("popped Value: %d\n", result);
                break;

            case 3:
                printf("Enter the index: ");
                scanf("%d", &userIndex);
                peep(s1, userIndex);
                break;

            case 4:
                show(s1);
                break;

            case 5:
                printf("\nThanks for Using me\n");
                getch();
                exit(0);
                break;
            default:
                break;
        }
        getch();
    }
}

int isEmpty(struct Stack *stack){
    if(stack->top == -1) return 1;
    return 0;
}

int isFull(struct Stack *stack){
    if(stack->top == stack->size - 1) return 1;
    return 0;
}

int push(struct Stack *stack, int data){
    if(isFull(stack) == 1){
        // printf("overflow! stack is full\n");
        return -1;
    }
    stack->top++;
    stack->ptr[stack->top] = data;
    return 1;
}

int pop(struct Stack *stack){
    int poppedValue = stack->ptr[stack->top];
    if(isEmpty(stack) == 1){
        // printf("overflow! stack is Empty\n");
        return -1;
    }
    stack->ptr[stack->top] = 0;
    stack->top--;
    return poppedValue;
}

int peep(struct Stack *stack, int index){
    if(index > stack->top || index < 0) return 0;
    return stack->ptr[index];
}

int show(struct Stack *stack){
    int i = 0;
    for(i = stack->size - 1; i >= 0; i--){
        printf("%d ", stack->ptr[i]);
    }
    printf("\n");
    return stack->top;
}