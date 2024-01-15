#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};


struct node* addNode(struct node *tree, int data) {
    if (tree == NULL) {
        struct node *root = (struct node *)malloc(sizeof(struct node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (data > tree->data) {
        tree->right = addNode(tree->right, data);
    }
    else if (data < tree->data) {
        tree->left = addNode(tree->left, data);
    }
    return tree;
}

void traverse(struct node *tree) {
    if (tree == NULL) {
        return;
    }
    else {
        traverse(tree->left);
        printf("%d ", tree->data);
        traverse(tree->right);
    }
}

int find(struct node *tree, int data) {
    if (tree == NULL) {
        return -1;
    }
    else if (tree->data == data) {
        return 1;
    }
    else if(find(tree->left, data) == 1) {
        return 1;
    }
    else if(find(tree->right, data) == 1) {
        return 1;
    }
    return -1;
}

int main() {
    struct node *tree = NULL;
    int choice;
    do {
        printf("1. Add Node\n");
        printf("2. Traverse\n");
        printf("3. Find\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                int data;
                scanf("%d", &data);
                tree = addNode(tree, data);
                break;
            case 2:
                traverse(tree);
                printf("\n");
                break;
            case 3:
                printf("Enter data: ");
                int findData;
                scanf("%d", &findData);
                find(tree, findData) == 1 ? printf("Found\n") : printf("Not Found\n");
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    }while (choice != 4);

    return 0;
}
