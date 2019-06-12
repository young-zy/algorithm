#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef int Elemtype;

struct Data{
    Elemtype num;
};

struct Node{
    struct Data * data;
    struct Node * next;
};

struct Stack{
    struct Node * head;
    long long size;
};

struct Queue{
    struct Node * head;
    struct Node * back;
    long long size;
};

struct Stack * Stack(){
    struct Stack* ans = (struct Stack *)malloc(sizeof(struct Stack));
    ans->head = (struct Node*)malloc(sizeof(struct Node));
    ans->head->data = NULL;
    ans->size = 0;
    ans->head->next = NULL;
    return ans;
}

struct Queue * Queue(){
    struct Queue* ans = (struct Queue *)malloc(sizeof(struct Queue));
    ans->head = (struct Node*)malloc(sizeof(struct Node));
    ans->head->data = NULL;
    ans->head->next = NULL;
    ans->back = ans->head;
    ans->size = 0;
    return ans;
}

void stack_pop(struct Stack* st){
    if(st->size > 0){
        struct Node* temp = st->head->next;
        st->head->next = temp->next;
        free(temp->data);
        free(temp);
        st->size--;
    }else{
        return;
    }
    
}

void queue_pop(struct Queue* qu){
    if(qu->size > 0){
        struct Node *temp = qu->head->next;
        qu->head->next = temp->next;
        free(temp->data);
        free(temp);
        qu->size--;
        if(qu->size == 0){
            qu->back = qu->head;
        }
    }
}

void stack_push(struct Stack *st,Elemtype num){
    struct Node *temp = st->head->next->next;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->next = temp;
    newnode->data = (struct Data *)malloc(sizeof(struct Data));
    newnode->data->num = num;
    st->head->next = newnode;
    st->size++;
}

void queue_push(struct Queue *qu, Elemtype num){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->next = NULL;
    newnode->data = (struct Data *)malloc(sizeof(struct Data));
    newnode->data->num = num;
    qu->back->next = newnode;
    qu->back = newnode;
    qu->size++;
}

Elemtype top(struct Stack *st){
    return st->head->next->data->num;
}

Elemtype front(struct Queue *qu){
    return qu->head->next->data->num;
}

int queue_isempty(struct Queue * qu){
    if(qu->size == 0){
        return 1;
    }else{
        return 0;
    }
}

int stack_isempty(struct Stack * st){
    if(st->size == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    
    return 0;
}