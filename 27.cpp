#include<bits/stdc++.h>

using namespace std;

int printnode(struct node * n,int * a);

struct node {
    struct node * father;
    struct node * lchild;
    struct node * rchild;
    int data;
    int num;
};

int main(){
    int input;
    scanf("%d",&input);
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * p;
    struct node * q;
    for(int i = 0;i< input;i++){
        if(i == 0){
            scanf("%d",&head -> data);
            p = head;
            p -> lchild = NULL;
            p -> rchild = NULL;
            p -> father = NULL;
            p -> num = 1;
        }else{
            p = (struct node *)malloc(sizeof(struct node));
            scanf("%d",&p -> data);
            p -> lchild =NULL;
            p-> rchild = NULL;
            q = head;
            while(1){
                if(q->data < p->data){
                    if(q -> lchild != NULL){
                        q = q -> lchild;
                    }else{
                        q -> lchild = p;
                        p -> father = q;
                        p -> num = q -> num * 2;
                        break;
                    }
                }else{
                    if(q -> rchild != NULL){
                        q = q -> rchild;
                    }else{
                        q -> rchild = p;
                        p -> father = q;
                        p -> num = q -> num * 2 + 1;
                        break;
                    }
                }
            }

        }
    }
    int a[(int)pow(2,20)];
    memset(a,-1,sizeof(a));
    printnode(head,a);
    int flag = 1;
    int count = 0;
    for(int i = 0; i < (int)pow(2,20) && count < input; i++){
        if(a[i]>=0){
            printf("%d",a[i]);
            count++;
        }else{
            flag = 0;
            continue;
        }
        if(count < input){
            printf(" ");
        }
    }
    if(flag == 1){
        printf("\nYES");
    }else{
        printf("\nNO");
    }
    system("pause");
    return 0;
}

int printnode(struct node * n,int * a){
    if(n -> lchild != NULL){
        printnode(n -> lchild,a);
    }
    if(n -> rchild != NULL){
        printnode(n -> rchild,a);
    }
    a[n -> num - 1] = n -> data;
    return 0;
}