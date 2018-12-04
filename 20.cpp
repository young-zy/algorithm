#include<bits/stdc++.h>

using namespace std;

struct node{
    struct node * previous;
    struct node * next;
    int data;
};


int main(){
    int temp;
    int num;
    struct node * p;
    struct node * q;
    struct node * head;
    int count = 0;
    scanf("%d",&num);
    scanf("%d",&temp);
    p = (struct node *)malloc(sizeof(struct node));
    p -> previous = NULL;
    p -> data = temp;
    head = p;
    while(temp >= 0){
        if(count == 0){
            scanf("%d",&temp);
            count++;
            continue;
        }
        q = p;
        p = (struct node *)malloc(sizeof(struct node));
        count++;
        q -> next = p;
        p -> previous = q;
        p -> data = temp;
        scanf("%d",&temp);
    }
    p -> next = NULL;
    struct node * end = p;
    if(num > count || num <= 0){
        printf("NULL");
        return 0;
    }
    if(num > count/2){
        p = head;
        num = count - num;
        for(int i = 0; i < num; i++){
            p = p -> next;
        }
        printf("%d",p -> data);
    }else{
        p = end;
        for(int i = 0;i < num-1;i++){
            p = p -> previous;
        }
        printf("%d",p -> data);
    }
    return 0;
}