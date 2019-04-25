#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0; i< (1<<n);i++){
        if(i != 0){
            cout<<" ";
        }
        cout<<((i>>1) ^ i);
    }
    return 0;
}