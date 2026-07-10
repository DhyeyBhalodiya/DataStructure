#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node* next;
};

struct Node * first ;

int main(){

    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node * current = first;
    while ( current != NULL){
        struct Node * temp = current;
        if(temp -> info == temp -> next -> info){
            int data = temp -> info;
            while (temp != NULL && temp->next->info == data){
                struct Node * deleteNode = temp->next;
                temp->next = deleteNode->next;
                free(deleteNode);
            }
        }
        else{
            struct Node* temp = temp->next->info;
        }
        current = temp;
    }
    
}
