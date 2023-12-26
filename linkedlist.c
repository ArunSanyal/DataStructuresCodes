#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link; //Address of next
};

struct node* root = NULL; //Global variable for access to all functions

struct linkedList{
    struct node* root;
};


void append(struct linkedList* a); //Add at end
int length(struct linkedList* a);
void addAtbeg(struct linkedList* a);
void insertAf(struct linkedList* a);
void display(struct linkedList* a);
void delete(struct linkedList* a);

int main(){

    struct linkedList ll;
    ll.root = NULL;
    int ch;

    while(1){
        printf("\nEnter\n1. Append\n2. Add at start\n3. InsertAfter\n4. Display\n5. Delete\n6. Exit\n");
        printf("Enter your choice here:");
        scanf("%d", &ch);

        switch(ch){

            case 1: append(&ll); //Add at end
                    break;
            
            case 2: addAtbeg(&ll);
                    break;

            case 3: insertAf(&ll);
                    break;

            case 4: display(&ll);
                    break;
            
            case 5: delete(&ll);
                    break;

            case 6: printf("You opted for exit function");
                    exit(0);
                    break; //not needed

            default: printf("Invalid input");
        }
    }    

    return 0;
}

void append(struct linkedList* a){
    struct node* temp;
    temp =(struct node*) malloc(sizeof(struct node));

    printf("\nEnter data here:");
    scanf("%d", &temp->data);

    temp->link = NULL; //NULL indicating that this node will be at end of linked list.

    if(a->root == NULL){
        a->root = temp;
    }
    else{
        struct node* p;
        p = a->root;
        while(p->link != NULL){
            p= p->link;
        }
        p->link = temp;
    }
}


int length(struct linkedList* a){
    struct node* p;
    int count = 0;

    p = a->root; //Now p points to first node

    while(p != NULL){
        count++;
        p= p->link;
    }
    //loop terminates means now p points to NULL

    return count;
}


void addAtbeg(struct linkedList* a){
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    printf("Enter data here:");
    scanf("%d", &temp->data);
    temp->link = a->root;
    a->root = temp;
}


void insertAf(struct linkedList* a){
    int n;
    printf("Enter after which position you want to insert:");
    scanf("%d", &n);
    
    int len = length(a);

    if(n>len){
        //Cannot enter after a node which doesn't exist
        printf("Invalid Position\n");
    }
    else{
        struct node* temp;
        struct node* p;

        temp = (struct node*) malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &temp->data);
        
        n--; //to reach the node we need 1 less step than the node number

        p=a->root;
        while(n--){
            p= p->link;
        }
        temp->link = p->link;
        p->link = temp;
    }   
}


void display(struct linkedList* a){
    struct node* p;
    p = a->root;

    if(p == NULL){
        printf("No nodes in the list\n");
    }
    else{
        while(p != NULL){
            printf("%d\t", p->data);
            p = p->link;
        }
        printf("\n");
    }

}




void delete(struct linkedList* a){
    int loc;
    printf("Enter the location:");
    scanf("%d", &loc);

    struct node* p;

    if(loc > length(a)){
        printf("Invalid location\n");
    }
    else if(loc == 1){ 
        p = a->root;
        a->root = p->link;
        p->link = NULL; //should not be connected to any node
        free(p);// freeing the deleted node
    }
    else{
        int i =1;
        struct node* q;
        p = a->root;
        while(i< loc-1){
            p = p->link;
            i++;
        }

        q= p->link;
        p->link = q->link;
        q->link = NULL; //should not point to any location.

        free(q);

    }
}