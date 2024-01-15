#include <stdio.h>

#define SIZE 10

int A[SIZE];

int HashFunction(int key) {
    return key % SIZE;
}

int Search(int dizi[], int veri) {
    int index = HashFunction(veri);

    while (dizi[index] != 0) {
        if (dizi[index] == veri) {
            return 1;
        }

        index = (index + 1) % SIZE;
    }

    return 0;
}

int Insert(int dizi[], int veri) {
    int index = HashFunction(veri);

    while (dizi[index] != 0) {
        index = (index + 1) % SIZE;
    }

    dizi[index] = veri;
    return 1;
}

int Delete(int dizi[], int veri) {
    int index = HashFunction(veri);

    while (dizi[index] != 0) {
        if (dizi[index] == veri) {
            dizi[index] = -1;
            return 1;
        }


        index = (index + 1) % SIZE;
    }

    return 0;
}

int main() {

    do{
        printf("1-Insert\n2-Search\n3-Delete\n4-Print\n5-Exit\n");
        int answer;
        scanf("%d", &answer);
        switch (answer) {
            case 1:
                printf("Enter a number to insert: ");
                int number;
                scanf("%d", &number);
                Insert(A, number);
                break;
            case 2:
                printf("Enter a number to search: ");
                int searchNumber;
                scanf("%d", &searchNumber);
                Search(A, searchNumber) == 1 ? printf("Found\n") : printf("Not Found\n");
                break;
            case 3:
                printf("Enter a number to delete: ");
                int deleteNumber;
                scanf("%d", &deleteNumber);
                Delete(A, deleteNumber) == 1 ? printf("Deleted\n") : printf("Not Found\n");
                break;
            case 4:
                for (int i = 0; i < SIZE; ++i) {
                    printf("%d ", A[i]);
                }
                printf("\n");
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(answer != 5);

    return 0;
}