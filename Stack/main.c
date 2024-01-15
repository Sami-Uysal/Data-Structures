#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int array[5], top;
void push(int x) {
    if (top +1 == 5)
        printf("Stack is full\n");
    else
        array[++top] = x;
}
void pop() {
    if (top == -1)
        printf("Stack is empty\n");
    else
        top--;
}
int peek() {
        return array[top];
}
void Clear() {
    top = -1;
}
void ScreenClear() {
    sleep(1);
    system("cls");
}

void print() {
    int i;
    printf("Stack: ");
    for (i = 0; i <= top; i++)
        printf("%d ", array[i]);
    printf("\n");
}
int main() {
    int choice, x;
    top = -1;
    do{
        printf("***********Menu***********\n");
        printf("1-Push\n");
        printf("2-Pop\n");
        printf("3-Peek\n");
        printf("4-Clear\n");
        printf("0-Exit\n");
        printf("**************************\n");
        printf("Your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a number:");
                scanf("%d", &x);
                push(x);
                if (top != -1) print();
                break;
            case 2:
                pop();
                if (top != -1) print();
                break;
            case 3:
                if (top == -1) printf("Stack is empty\n");
                else printf("%d\n", peek());
                break;
            case 4:
                Clear();
                break;
            case 0:
                printf("Good bye\n");
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
        ScreenClear();
    }while (choice != 0);
    return 0;
}
