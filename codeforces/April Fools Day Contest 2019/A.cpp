#include<bits/stdc++.h>

using namespace std;

int c[18];

int check(int a, int b){
    for(int i = a ; i < b-1 ;i++){
        if(c[i] > c[i+1]){
            return max(check(a,(a+b)/2),check((a+b)/2,b));
        }
    }
    return b-a;
}

int main(){
    int n;
    cin>>n;
    
    for(int i = 0; i< n ; i++){
        cin>>c[i];
    }
    cout<<check(0,n);
    return 0;
}