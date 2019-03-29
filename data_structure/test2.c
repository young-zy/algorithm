#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Data{
    long long x;
};

struct node * head1;
struct node * head2;

struct node{
    struct Data * data;
    struct node * next;
};

long long int_pow(long a, int b){
    long long res = 1;
    for(int i = 0 ; i < b;i++){
        res *= a;
    }
    return res;
}

int input(long long * x){
    long long result = 0;
    char ch[10000];
    int i = 0;
    ch[i] = getchar();
    while(ch[i] == ' ' || ch[i] == '\n'){
        ch[i] = getchar();
    }
    if(ch[i] <= '0' || ch[i] >= '9'){
        return 0;
    }
    while(ch[i] != ' ' && ch[i] != '\n'){
        if(ch[i] < '0' || ch[i] > '9'){
            return 0;
        }
        i++;
        ch[i] = getchar();
    }
    i--;
    for(int j = 0;i>=0;i--,j++){
        result += (ch[j] - '0') * int_pow(10,i);
    }
    *x = result;
    return 1;
}

int output(struct node * head){
    struct node *p = head -> next;
    while(p != NULL){
        printf("%lld ",p->data->x);
        p = p->next;
    }
    return 1;
}

int seperate(struct node * no){
    int count = 1;
    no = no->next;
    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    struct node *p1 = head1;
    struct node *p2 = head2;
    for(int count = 1;no != NULL;count++,no = no->next){
        if(count % 2 == 0){
            p1->next = (struct node *)malloc(sizeof(struct node));
            p1->next->data = no->data;
            p1 = p1->next;
            p1->next = NULL;
        }else{
            p2->next = (struct node *)malloc(sizeof(struct node));
            p2->next->data = no->data;
            p2 = p2->next;
            p2->next = NULL;
        }
    }
}

int main(){
    long long n;
    scanf("%lld",&n);
    if(n==0){
        return 0;
    }
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    p->next = NULL;
    struct node * q;
    for(long long  i = 0 ; i< n ; i++){
        q = (struct node *)malloc(sizeof(struct node));
        q->next = NULL;
        p-> next = q;
        p = p->next;
        q->data = (struct Data *)malloc(sizeof(struct Data));
        //scanf("%lld",&q->data->x);
        while(!input(&q->data->x)){
            printf("ERROR , PLS ENTER NUMBER AGAIN!\n");
        }
        q->next = NULL;
    }
    output(head);
    printf("\n");
    seperate(head);
    output(head1);
    printf("\n");
    output(head2);
    return 0;
}
