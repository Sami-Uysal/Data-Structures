#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

int addNodePosition(int data) {

    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    int position;
    struct node *temp = head;
    printf("Enter position: ");
    scanf("%d", &position);
    if(position==1){
        ptr->next = head;
        head = ptr;
        return;
    }

    for(int i=1; i<position-1; i++){
        temp = temp->next;
    }

    ptr->next = temp->next;
    temp->next = ptr;

}

int addNode(int data) {

    if (head == NULL) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;

        head = tail = newNode;
    }
    else {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;

    }
    return 0;
}

int addNodeHead(int data) {

    if(head==NULL){
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;

        head = tail = newNode;
    }
    else{
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;

        head = newNode;
    }
}

int deleteNode(int data) {
    struct node *temp = head;
    struct node *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return 0;
    }

    if(head->data == data){
        struct node *t = head;
        head = head->next;
        free(t);
        return 0;
    }

    while(temp!=NULL && temp->data != data){
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL){
        printf("Node not found\n");
        return 0;
    }
    prev->next = temp->next;
    if(tail->data==data) {
        tail = prev;
    }
    free(temp);

    return 0;
}

int printList() {

    printf("Linked List: ");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {

    int answer;
    int data;

    do {
        printf("1-Add Node\n2-Add Node Head\n3-Add Node Position\n4-Delete Node\n5-Print List\n6-Exit\n");
        scanf("%d", &answer);
        switch (answer) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(data);
                printf("\n");
                printList();
                printf("\n");
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                addNodeHead(data);
                printf("\n");
                printList();
                printf("\n");
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                addNodePosition(data);
                printf("\n");
                printList();
                printf("\n");
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                deleteNode(data);
                printf("\n");
                printList();
                printf("\n");
                break;
            case 5:
                printf("\n");
                printList();
                printf("\n");
                break;
            case 6:
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    } while (answer != 6);

    return 0;
}
