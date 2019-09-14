#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w;
    cin>>w;
    if(w % 2){
        cout<<"NO";
    }else if((w/2) % 2 == 0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}