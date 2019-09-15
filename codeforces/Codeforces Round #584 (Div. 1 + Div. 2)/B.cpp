#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[105],b[105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count = 0;
    for(int i = 0; i<n ; i++){
        if(s[i] == '1'){
            count++;
        }
    }
    if(count == n){
        cout<<count;
        return 0;
    }
    for(int i = 0; i<n ; i++){
        cin>>a[i]>>b[i];
    }
    int ans = count;
    for(int t = 1; t<=100000;t++){
        for(int i = 0; i<n ; i++){
            if(t-b[i] >= 0 && (t -b[i])%a[i] == 0){
                if(s[i] == '1'){
                    s[i] = '0';
                    count--;
                }else{
                    s[i] = '1';
                    count++;
                }
            }
        }
        ans = max(count,ans);
    }
    cout<<ans;
    return 0;
}