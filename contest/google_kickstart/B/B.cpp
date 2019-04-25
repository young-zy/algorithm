#include<bits/stdc++.h>

using namespace std;

struct node{
    int s;
    int e;
    int l;
};

struct node no[105];

int time = 0;

bool cmp(struct node a, struct node b){
    return a.e/a.l < b.e/b.l;
}

int main(){
    int t;
    cin>>t;
    for(int i = 0; i< t; i++){
        int n;
        cin>>n;
        priority_queue<struct node> pq;
        for(int j = 0;j<n ; j++){
            cin>>no[i].s>>no[i].e>>no[i].l;
        }


    }
    return 0;
}