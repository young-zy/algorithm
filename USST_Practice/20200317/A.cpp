#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long ans = 0;
    for(int i = 0; i<=n;i++){
        if(i % 7 != 0){
            int flag = 1;
            int temp = i;
            while(temp){
                if(temp % 10 == 7){
                    flag = 0;
                    break;
                }
                temp /= 10;
            }
            if(flag == 1){
                ans += i*i;
            }
        }
    }
    cout<<ans;
    return 0;
}