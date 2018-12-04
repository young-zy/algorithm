#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * next;
};

int main(){
    int num,m;
    scanf("%d %d",&num,&m);
    int a[num];
    struct node * head = (struct node *)malloc(sizeof(struct node));
    head -> next =NULL;
    scanf("%d",&head -> data);
    struct node * p = head;
    for(int i = 1;i < num;i++){
        struct node * q;
        q = p;
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&p -> data);
        q -> next = p;
        p ->next = NULL;
    }
    for(int i = 0; i<m;i++){
        struct node * q= head;
        head = head -> next;
        q ->next  =NULL;
        struct node * p = head;
        while(p -> next){
            p = p-> next;
        }
        p ->next = q;
    }
    p = head;
    for(int i =0;i<num;i++){
        if(i !=0){
            printf(" ");
        }
        printf("%d",p -> data);
        p = p->next;
    }
    return 0;
}