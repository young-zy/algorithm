#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n){
        if(n == 0){
            return 0;
        }
        long long count = 0;
        for(int i = 1; i<=n/2 ; i++){
            if((n-i) % i == 0){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}