#include<bits/stdc++.h>

using namespace std;

void initnode(struct node * p);

struct node * iterate(int num,int bl, int br,int al,int ar,int a[],int b[]);

struct node {
    struct node * father;
    struct node * left;
    struct node * right;
    int data;
};

struct index{
    int _index;
    int data;
    friend bool operator < (struct index a,struct index b){
        return a._index < b._index;
    }
};

void initnode(struct node * p){
    p ->father = nullptr;
    p -> left = nullptr;
    p -> right = nullptr;
}

int countl = 0;

struct node * iterate(int num,int bl, int br,int al,int ar,int a[],int b[]){
    struct node * p = (struct node *)malloc(sizeof(struct node ));
    countl ++;
    initnode(p);
    p -> data = b[br];
    int temp;
    int newal,newar,newbl,newbr;
    for(int  i = al; i <= ar;i++){
        if(a[i] == b[br]){
            temp = i;
            break;
        }
    }
    newal = temp + 1;
    newar = temp - 1;
    if(temp == 0 && br != 0){
        p -> right = iterate(num,bl,num - countl - 1,newal,ar,a,b);
        p -> right -> father = p;
        return p;
    }
    if(temp != ar && temp != al){
        p -> right = iterate(num,bl,num - countl - 1,newal,ar,a,b);
        p -> right -> father = p;
        if(al == newar && al == 0){
            p -> left = (struct node * )malloc(sizeof(struct node));
            initnode(p->left);
            p -> left -> data = a[al];
            p -> left -> father = p;
            countl++;
            return p;
        }
        p -> left = iterate(num,bl,num - countl - 1,al,newar,a,b);
        p -> left -> father = p;
        return p;
    }else if(temp == ar &&temp != al){
        p -> left = iterate(num,bl,num - countl - 1,al,ar-1,a,b);
        p -> left -> father = p;
        return p;
    }else{
        return p;
    }
    return p;
}

void save(set<struct index> &s,int k,struct node * p){
    struct index q;
    q._index = k;
    q.data = p -> data;
    s.insert(q);
    if(p -> left != NULL){
        save(s,2*k,p->left);
    }
    if(p -> right != NULL){
        save(s,2*k+1,p->right);
    }
}

int main(){
    int num;
    int n = 0;
    scanf("%d",&num);
    if(num == 0){
        return 0;
    }
    set<struct index> s;
    int a[num],b[num];
    for(int i = 0; i<num;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0; i<num;i++){
        scanf("%d",&b[i]);
    }
    struct node * head = iterate(num,0,num-1,0,num-1,a,b);
    save(s,1,head);
    int count = 0;
    int start = 1;
    int end = 1;
    set<struct index>::iterator it; 
    set<struct index>::reverse_iterator rit;
    for(int i = 0; count < num;i++){
        if(i% 2 == 0){
            for(rit = s.rbegin();rit != s.rend();++rit){
                if(rit -> _index < start){
                    break;
                }else if(rit -> _index > end){
                    continue;
                }else{
                    if(count != 0){
                        printf(" ");
                    }
                    printf("%d",rit -> data);
                    count++;
                }
            }
        }else{
            for(it = s.begin();it != s.end();++it){
                if(it -> _index < start){
                    continue;
                }else if(it -> _index > end){
                    break;
                }else{
                    if(count != 0){
                        printf(" ");
                    }
                    printf("%d",it -> data);
                    count++;
                }
            }
        }
        start *= 2;
        end = end*2 +1;
    }
    system("pause");
    return 0;
}