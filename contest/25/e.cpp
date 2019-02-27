#include<bits/stdc++.h>

using namespace std;

int a[1000];
int b[1000];
int n;

struct node{
    struct node * le;
    struct node * ri;
    int num;
};

node* out(int num,int start,int end){
    int root;
    for(int i = start; i<=end ;i++){
        if(b[i] == a[num]){
            root = i;
            break;
        }
    }
    node * no = new node;
    no->num = a[num];
    no->le = NULL;
    no->ri = NULL;
    if(root != start && root !=0){
        no->le = out(num+1,start,root-1);
    }
    if(root != end){
        no->ri = out(num+root-1,root+1,end);
    }

    return no;
}



int main(){
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    
    scanf("%d",&n);
    for(int i = 0; i<n ;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0; i<n;i++){
        scanf("%d",&b[i]);
    }
    node * root = out(0,0,n-1);
    return 0;
}