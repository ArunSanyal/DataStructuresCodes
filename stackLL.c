#include <stdio.h>
#include <stdlib.h>

//creating node(since we making stack using linked list)
struct node {
    int data;
    struct node* next;
};

//Structure for stack. It includes only one field i.e top, since data is stored in node.
struct stack{
    struct node* top;  //top pointer of type "node", to point topmost node.
};

void push(struct stack* s);  //nodes get created in this function
void display(struct stack* s);
void pop(struct stack* s);
void peek(struct stack* s);
void totEle(struct stack* s);

int main(){

    struct stack s;
    s.top = NULL;
    int ch;

    while(1){
        printf("Enter\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Total Elements\n6. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);

        switch(ch){
            case 1: push(&s);
                    break;

            case 2: pop(&s);
                    break;

            case 3: peek(&s);
                    break;

            case 4: display(&s);
                    break;

            case 5: totEle(&s);
                    break;

            case 6: printf("\nYou opted for exit function");
                    exit(0);
                    break;


            default: printf("Invalid input\n");
        }
    }

    
    return 0;
}

void push(struct stack* s){
    struct node* temp;

    temp = (struct node* ) malloc (sizeof(struct node));

    printf("Enter data:");
    scanf("%d", &temp->data);

    temp->next = s->top; //Newly created node will point to node that was being pointed by top.
    s->top = temp;

}

void display(struct stack* s){

    if(s->top == NULL){
        printf("Stack underflow\n");
    }
    else{

        struct node* p;
        p = s->top;  //temporary pointer, to avoid manipulating the top pointer

        while(p != NULL){
        printf("%d\t", p->data);
        p = p->next;
        }
        printf("\n");
    }
}

void pop(struct stack* s){
    if(s->top == NULL){
        printf("Stack underflow\n");
    }
    else{
        struct node* p;
        printf("The popped element:%d\n", s->top->data);
        p = s->top;
        s->top = s->top->next;
        free(p);
    }
}

void peek(struct stack* s){
    if(s->top == NULL){
        printf("Stack underflow");
    }
    else{
        printf("The top element: %d\n", s->top->data);
    }
}

void totEle(struct stack* s){
    struct node* p = s->top;

    int count =0;

    while(p != NULL){
        p = p->next;
        count++;
    }

    printf("Total number of elements: %d\n", count );
}