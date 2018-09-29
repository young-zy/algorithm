#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    int num;
    struct node * next;
};

int main(){
    int input;
    struct node * head;
    head = (struct node *)malloc(sizeof(struct node));
    head -> num =0;
    scanf("%d",&input);
    for(int i = 0; i< input ;i++){
        int temp;
        scanf("%d",&temp);
        if(i == 0){
            head -> data = temp;
            head -> num++; 
            head -> next = NULL;
        }else{
            struct node * p = head;
            while(p -> next != NULL){
                if(p -> data == temp){
                    p -> num++;
                    break;
                }
                p = p-> next;
            }
            if(p -> next == NULL){
                if(p -> data == temp){
                    p -> num++;
                }else{
                    p -> next = (struct node *)malloc(sizeof(struct node));
                    p -> next ->data = temp;
                    p -> next -> num = 1; 
                    p -> next -> next = NULL;
                }
            }
        }
    }
    int max = 0;
    int maxnum = 0;
    struct node * p = head;
    while(p != NULL){
        if(p -> num > max){
            maxnum = p -> data;
            max = p -> num;
        }
        p = p->next;
    }   
    printf("%d %d",maxnum,max);
    return 0;
}