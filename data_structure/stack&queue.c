#include<stdio.h>
#include<string.h>
#include<math.h>

typedef int Elemtype;

struct Data{
    Elemtype num;
};

struct Node{
    struct Data * data;
    struct node * next;
};

struct Stack{
    struct Node * head;
    long long size;
};

struct Queue{
    struct Node * head;
    long long size;
};

struct Stack * Stack(){
    struct Stack* ans = (struct Stack *)malloc(sizeof(struct Stack));
    ans->head = (struct Data*)malloc(sizeof(struct Data));
    ans->head->data = NULL;
    ans->size = 0;
    return ans;
}

struct Queue * Queue(){
    struct Queue* ans = (struct Queue *)malloc(sizeof(struct Queue));
    ans->head = (struct Data*)malloc(sizeof(struct Data));
    ans->head->data = NULL;
    ans->size = 0;
    return ans;
}

void Stack_pop(struct Stack* st){
    if(st->size > 0){
        struct Node* temp = st->head->next;
        st->head->next = temp->next;
        free(temp);
    }else{
        return;
    }
    
}

int main(){
    
    return 0;
}