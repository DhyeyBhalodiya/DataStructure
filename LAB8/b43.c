#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int info;
    struct Node* link;
};

struct Node* first = NULL;

struct Node * newNode(int x){
    
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> info = x ;
    newNode -> link = NULL ;
    return newNode;
};

bool equalNode(struct Node * a,struct Node * b){

    while (a!=NULL && b!=NULL)
    {
        if (a -> info != b -> info)
        {
            return false;
        }
        a = a -> link;
        b = b -> link;
    }

    return(a == NULL && b == NULL);
    
}

int main(){

    struct Node * a = newNode(1);
    a -> link = newNode(2);
    a -> link -> link = newNode(3);

    struct Node * b = newNode(1);
    b -> link = newNode(2);
    b -> link -> link = newNode(3);
    
    if (equalNode(a,b)){
        printf("Nodes are equal");
    }
    else{
        printf("Nodes are not equal");
    }
    
    return 0;
}
