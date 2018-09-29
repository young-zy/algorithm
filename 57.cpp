#include<bits/stdc++.h>

using namespace std;

struct node {
    int tag;
    int num;
    struct node * next;
};

int main(){
    int n;
    scanf("%d",&n);
    struct node * head;
    for(int i = 0; i<n;i++){
        int k;
        scanf("%d",&k);
        for(int j =0;j<k;j++){
            int temp;
            scanf("%d",&temp);
            if(i == 0 && j ==0){
                head = (struct node *)malloc(sizeof(struct node));
                head -> next = NULL;
                head -> tag = temp;
                head -> num = 1;
            }else{
                struct node *p;
                p = head;
                while(p ->next !=NULL){
                    if(temp == p -> tag){
                        p -> num++;
                        break;
                    }
                    p = p->next;
                }
                if(temp == p -> tag){
                    p -> num++;
                    break;
                }
                p -> next = (struct node *)malloc(sizeof(struct node));
                p = p->next;
                p ->tag = temp;
                p ->num = 1;
                p -> next = NULL;
            }
        }
    }
    int max = 0;
    int maxtag = 0;
    struct node * p =head;
    while(p != NULL){
        if(p -> num >=max){
            if(p -> num == max && p->tag>maxtag){
                maxtag = p->tag;
            }else if(p ->num > max){
                max = p -> num;
                maxtag = p ->tag;
            }
        }
        p = p ->next;
    }
    printf("%d %d",maxtag,max);
    return 0;
}