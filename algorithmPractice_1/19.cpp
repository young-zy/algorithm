#include<bits/stdc++.h>

using namespace std;

struct node{
    struct node * previous;
    struct node * next;
    int num;
};


int main(){
    int input;
    scanf("%d",&input);
    struct node * start;
    struct node * end;
    struct node * p;
    struct node * q;
    for(int i=0;i<input;i++){
        q = p;
        p = (struct node *)malloc(sizeof(struct node));
        if(i == 0){
            start = p;
            start -> num = 1;
            continue;
        }
        if(i == input -1){
            end = p;
            q -> next = end;
            end -> previous = q;
            end -> next = start;
            start -> previous = end;
            if(input == 2){
                start -> next = p;            
            }
            end -> num = input;
            continue;
        }
        p -> num = i+1;
        p -> previous = q;
        q -> next = p;
    }
    int quant = input;
    while(quant != 1){
        p = start;
        for(int i = 0; i<3; i++){
            if(i == 2){
                p-> previous ->next = p->next;
                p -> next ->previous = p->previous;
                start = p -> next;
                free(p);
                quant--;
                continue;
            }
            p = p -> next;
        }
    }
    printf("%d",start->num);
    return 0;
}