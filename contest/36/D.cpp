#include<bits/stdc++.h>

using namespace std;

struct node{
    string a;
    int flag;
};

bool cmp(node  a,node b){
    return a.a.length() > b.a.length();
}

int main(){
    int n;
    cin>>n;
    struct node no[n];
    for(int i = 0; i< n ; i++){
        cin>>no[i].a;
        no[i].flag = 0;
    }
    no[0].flag =1;
    int change = 1;
    while(change){
        change = 0;
        for(int i = 0;i < n;i++){
            if(no[i].flag == 1){
                continue;
            }else{
                for(int j =0 ;j<n ;j++){
                    if(no[j].flag == 0){
                        continue;
                    }
                    if(no[i].a.find(no[j].a) != string::npos || no[j].a.find(no[i].a) != string::npos){
                        no[i].flag = 1;
                        change++;
                    }
                }
            }
        }
    }
    int flag = 1;
    for(int i = 0; i<n ; i++){
        if(no[i].flag == 0){
            flag = 0;
            break;
        }
    }
    if(flag == 0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}