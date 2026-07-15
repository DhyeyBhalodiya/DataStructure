#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

struct Node* first = NULL;

void display() {
    struct Node* save = first;
    if (save == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

int countNodes() {
    int count = 0;
    struct Node* save = first;
    while (save != NULL) {
        count++;
        save = save->link;
    }
    return count;
}

void insertAtFront(int x) {
    struct Node* save = (struct Node*)malloc(sizeof(struct Node));
    save->info = x;
    save->link = first;
    first = save;
}

void insertAtEnd(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = x;
    newNode->link = NULL;
    if (first == NULL) {
        first = newNode;
        return;
    }
    struct Node* temp = first;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
}

void deleteFirstNode() {
    if (first == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node * save = first;
    first = first->link;
    free(save);
}

void deleteLastNode() {
    if (first == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (first->link == NULL) {
        free(first);
        first = NULL;
        return;
    }
    struct Node* temp = first;
    while (temp->link->link != NULL) {   // <- second-last node sudhi jaવાનું
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
}

void insertAtPos(int pos,int value){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;


        if (pos == 1){
            newNode->link = first;
            first = newNode;
        }else{
            struct Node* prev = first;
            for (int i = 1; i <= pos-2; i++){
                prev = prev -> link;
            }
            newNode->link = prev->link;
            prev->link = newNode;
        }
}

int main() {
    int choice, x, pos;
    while (1) {
        printf("\n1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete First Node\n");
        printf("4. Delete Last Node\n");
        printf("5. Display List\n");
        printf("6. Count Nodes\n");
        printf("7. Insert at Any position\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n') {}
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                if (scanf("%d", &x) != 1) {
                    while (getchar() != '\n') {}
                    break;
                }
                insertAtFront(x);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                if (scanf("%d", &x) != 1) {
                    while (getchar() != '\n') {}
                    break;
                }
                insertAtEnd(x);
                break;
            case 3:
                deleteFirstNode();
                break;
            case 4:
                deleteLastNode();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &x);
                insertAtPos(pos, x);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}