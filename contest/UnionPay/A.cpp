#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0; te < t; te++){
        long long n,m,k;
        cin>>n>>k>>m;
        long long k1 = k;
        string s;
        cin>>s;
        long long count = 0;
        for(int i = 0; i<n ; i++){
            if(s[i] == '1'){
                count++;
            }else{
                if(k>0){
                    k--;
                }else{
                    count--;
                }
            }
        }
        long long ans = 0;
        if(count < 0){
            ans = 0;
            count = 0;
            for(int i = 0; i<min(m,2ll) ;i++){
                int k2= k1;
                for(int j = 0; j<n ; j++){
                    if(s[j] == '1'){
                        count++;
                    }else{
                        if(k2>0){
                            k2--;
                        }else{
                            count--;
                        }
                    }
                    ans = max(ans,count);
                }
            }
        }else{
            count *= m-1;
            ans = count;
            for(int i = 0; i<n ; i++){
                if(s[i] == '1'){
                    count++;
                }else{
                    if(k1>0){
                        k1--;
                    }else{
                        count--;
                    }
                }
                ans = max(ans,count);
            }
        }
        if(ans < 0){
            ans = 0;
        }
        cout<<ans<<endl;
    }
    return 0;
}