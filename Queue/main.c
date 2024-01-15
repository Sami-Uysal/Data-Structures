#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define QUEUE_SIZE 5

int queue[QUEUE_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == QUEUE_SIZE-1 ) {
        printf("Queue is full\n");
    }
    else {
        queue[rear] = data;
        rear++;
    }

}

int dequeue() {
    if (front == rear) {
        front=-1;
        rear=-1;
        return -1;
    }

    else{
        int data = queue[front];
        front++;
        return data;
    }


}

void peek() {
    if (front == rear) {
        printf("Queue is empty\n");
    }
    else {
        printf("%d\n", queue[front]);
    }
}

void Clear() {
    front = -1;
    rear = -1;
}
void ScreenClear() {
    sleep(1);
    system("cls");
}

void printQueue() {
    printf("Queue: ");
    if (front == rear) {
        printf("Queue is empty\n");
    }

    for (int i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    int data;
    do{
        printf("********Menu********\n");
        printf("1-Enqueue\n");
        printf("2-Dequeue\n");
        printf("3-Peek\n");
        printf("4-Clear\n");
        printf("0-Exit\n");
        printf("********************\n");
        printf("Your choice: \n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                if (rear != QUEUE_SIZE) {
                    printQueue();
                }

                break;

            case 2:
                data = dequeue();
                if (data == -1) {
                    printf("Queue is empty\n");
                }
                else {
                    printf("Dequeued data: %d\n", data);
                    printQueue();
                }
                break;
            case 3:
                peek();
                break;
            case 4:
                Clear();
                printf("Queue is cleared\n");
                break;
            case 0:
                printf("Good Bye.\n");
                break;

            default:
                printf("Wrong choice\n");
                break;
        }
        ScreenClear();
    }while(choice != 0);

    return 0;
}
