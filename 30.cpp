#include<bits/stdc++.h>

using namespace std;

struct node {
    int p;
    int k;
    struct node * next;
};

int checkPrime(long int a);

int main(){
    long int input;
    scanf("%ld",&input);
    long int ans = input;
    struct node * head = NULL;
    if(input == 1){
        printf("1=1");
        return 0;
    }else{
        for(int i = 1; input % 2 == 0; i++){
            if(i == 1){
                head = (struct node *)malloc(sizeof(node));
                head -> next = NULL;
                head -> p = 2;
            }
            head -> k = i;
            input /= 2;
            if(checkPrime(input) && input != 1 ){
                struct node * p = (struct node *)malloc(sizeof(node));
                head -> next  = p;
                p-> p =input;
                p -> k = 1;
                p -> next = NULL;
            }
        }
        struct node * p = head;
        while(!checkPrime(input)){
            for(int i=3;i<=sqrt(input);i+=2){
                if(!checkPrime(i)){
                    continue;
                }
                int count = 1;
                while(input % i == 0){
                    struct node * q = p;
                    if(count == 1){
                        p = (struct node *)malloc(sizeof(struct node));
                        p -> p = i;
                        p -> next = NULL;
                        if(head == NULL){
                            head = p;
                        }else{
                            q -> next = p;
                        }
                    }
                    p -> k = count;
                    input /= i;
                    count ++;
                }
            }
        }
        if(input != 1){
            struct node * q = (struct node *)malloc(sizeof(struct node));
            q -> p = input;
            q -> k = 1;
            q->next = NULL;
            if(p == NULL){
                head = q;
            }else{
                p -> next = q;
            }
        }
    }
    struct node *p = head;
    int count = 1;
    printf("%ld=",ans);
    while(p != NULL){
        if(count != 1){
            printf("*");
        }
        printf("%d",p -> p);
        if(p -> k != 1){
            printf("^%d",p -> k);
        }
        p = p->next;
        count ++;
    }
    return 0;
}

int checkPrime(long int a){
    if(a % 2 == 0){
        return 0;
    }
    if(a % 3 == 0 && a != 3){
        return 0;
    }
    for(int i = 3;i <= sqrt(a); i=i+2){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}