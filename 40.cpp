#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * next;
    struct node * prev;
};

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    struct node * head[n];
    struct node * p;
    struct node * q;
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            q = p;
            p = (struct node *)malloc(sizeof(struct node));
            if(j == 0){
                head[i] = p;
                p -> prev = NULL;
            }else{
                p -> prev = q;
                q -> next = p;
            }
            scanf("%d",&p -> data);
            if(n == 1){
                printf("%d ",p -> data);
                return 0;
            }
            p -> next = NULL;
        }
    }
    for(int i = 0; i<m;i++){
        for(int j = 0;j<n;j++){
            struct node * p = head[j];
            while(p ->next != NULL){
                p = p->next;
            }
            struct node * temp = head[j];
            p -> prev -> next = NULL;
            head[j] = p;
            p -> prev = NULL;
            p -> next = temp;
            p -> next -> prev = p; 
        }
    }
    for(int i = 0;i<n;i++){
        struct node * p = head[i];
        for(int j = 0; j<n;j++){
            printf("%d ",p -> data);
            p = p-> next;
        }
        printf("\n");
    }

    return 0;
}