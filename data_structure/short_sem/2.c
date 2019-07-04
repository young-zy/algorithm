#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 100000

int a[maxn];

struct Data{
    char name[11];
    char num[11];
};

struct Node {
    struct Data* data;
    struct Node * next;
};

struct treenode{
    struct treenode * left;
    struct treenode * right;
    double grade;
    struct Node * head;
};

int del_stu(struct treenode * t,char * num,double grade){
    if(t == NULL){
        return -1;
    }
    int flag = 0;
    if(grade == t->grade){
        struct Node * p = t->head;
        while(p->next != NULL){
            if(!strcmp(num,p->next->data->num)){
                free(p->next->data);
                p->next = p->next->next;
                free(p->next);
                flag = 1;
                break;
            }
            p = p->next;
        }
        if(flag == 0){
            return -1;
        }else{
            return 0;
        }
    }else if(grade > t->grade){
        del_stu(t->left,num,grade);
    }else{
        del_stu(t->right,num,grade);
    }
}
