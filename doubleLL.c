#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct dll{
    struct node* root;
};

struct node* createNode(){
    struct node* ptr = (struct node* ) malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    ptr->prev = NULL;

    return ptr;
}

int length(struct dll* a){
    if(a->root == NULL){
        return 0;
    }
    else{
        int count =1;
        struct node* p = a->root;

        while(p->next != NULL){
            count++;
            p = p->next;
        }
        return count; 
    }
}


void append(struct dll* a){
    struct node* temp = createNode();

    if(a->root == NULL){
        a->root = temp;
    }
    else{
        struct node* p = a->root;

        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
        temp->prev = p; 
    }
}

void insertAtBeg(struct dll* a){
    struct node* temp = createNode();

    if(a->root == NULL){
        a->root = temp;
    }
    else{

        a->root->prev = temp;
        temp->next = a->root;
        a->root = temp;

    }
}

void insertAf(struct dll* a){

    if(a->root == NULL){
        printf("Linked List not yet created.\n");
    }
    else{
        int n;
        printf("Enter position after which you want add node: ");
        scanf("%d", &n);

        if(n>length(a)){
            printf("No such position so far.\n");
        }
        else if(n == length(a)){
            append(a);
        }
        else{
            int count =1;
            struct node* p = a->root;
            while(count < n){
                count++;
                p = p->next;
            }
            struct node* temp = createNode();
            temp ->next = p->next;
            temp ->prev = p;
            p->next = temp;
            temp->next->prev = temp;
        }
    }
}

void display(struct dll* a){
    if(a->root == NULL){
        printf("Linked list not created\n");
    }
    else{
        struct node* p = a->root;
        while(p != NULL){
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void delete(struct dll* a){
    if(a->root == NULL){
        printf("Linked list not created.\n");
    }
    else{
        int n;
        display(a);
        printf("Which Position to delete: ");
        scanf("%d", &n);
        if(n> length(a)){
            printf("Check the position you entered\n");
        }
        else if(n == 1){
            struct node* r = a->root;
            a->root = r->next;
            r->next->prev = NULL;
            free(r);
        }
        else{
            int count =1;
            struct node* p = a->root;
            while(count < n){
                count++;
                p = p->next;
            }
            struct node* q = p->prev;
            q->next = p->next;
            p->next->prev = q;
            free(p);
        }
    }
}



//Main  
int main(){

    struct dll d;
    d.root = NULL;

    int ch;

    while(1){

        printf("\nEnter\n1. Append\n2. Insert At Start\n3. Insert after\n4. Delete At\n5. Display\n6. Length\n7. Exit\n");
        printf("Enter here:");
        scanf("%d", &ch);

        switch(ch){
            case 1: append(&d);
                    break;

            case 2: insertAtBeg(&d);
                    break;

            case 3: insertAf(&d);
                    break;

            case 4: delete(&d);
                    break;

            case 5: display(&d);
                    break;

            case 6: printf("Current Length: %d\n", length(&d));
                    break;

            case 7: printf("\nOpted for exit function\n");
                    exit(0);
                    break;

            default: printf("Check your inputs\n");

        }
    }

    return 0;
}