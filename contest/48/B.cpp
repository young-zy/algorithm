#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long a[10005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    for(int i = 0; i< n; i++){
        cin>>a[i];
    }
    if(n == 1){
        cout<<1;
    }else if(n == 3){
        cout<<6;
    }else if(n % 4 == 0){
        cout<<4;
    }else if( n % 4 == 1){
        cout<<2*n;
    }else if(n %4 == 2){
        cout<<n;
    }else{
        cout<<12;
    }
    return 0;
}