#include<bits/stdc++.h>

using namespace std;

struct node{
    long a;
    long b;
    int flag = 0;
};

struct node no[300005];

bool cmp(struct node a,struct node b){
    if(a.a - a.b  ==  b.a -b.b){
        return a.b > b.b;
    }
    return  a.a - a.b > b.a - b.b;
}

int turna;

bool cmp2(struct node a,struct node b){
    if(((a.a<<turna) - max(a.a, a.b))  ==  ((b.a<<turna) -max(b.a ,b.b))){
        return a.b < b.b;
    }
    return ((a.a<<turna) - max(a.a, a.b))  >  ((b.a<<turna) - max(b.a, b.b));
}

int main(){
    long n;
    long b;
    cin>>n>>turna>>b;
    unsigned long long res = 0;
    for(long i = 0; i<n ; i++){
        scanf("%ld %ld",&no[i].a,&no[i].b);
    }
    if(b > 0){
        sort(no,no+n,cmp2);
        no[0].a <<= turna;
    }
    sort(no,no+n,cmp);
    long index = 0;
    while(b && index < n){
        if(no[index].a > no[index].b){
            b--;
            res += no[index].a;
        }else{
            res += no[index].b;
        }
        index++;
    }
    index--;
    while(index++ != n-1){
        res += no[index].b;
    }
    cout<<res;
    return 0;
}