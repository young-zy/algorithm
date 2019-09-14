#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int last;
    int count = 1;
    long long ans = 0;
    for(int i = 0; i<n ;i++){
        cin>>a[i];
        if(i == 0){
            last = a[i];
        }else{
            if(a[i] != last){
                ans += (long long)(1+count)*count/2;
                last = a[i];
                count = 1;
            }else{
                count++;
            }
        }
    }
    ans += (long long)(1+count)*count/2;
    cout<<ans;
    return 0;
}