#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

unordered_map<long long,int> uma;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long b1,q,l,m;
    cin>>b1>>q>>l>>m;
    int a;
    for(int i = 0; i<m;i++){
        cin>>a;
        uma[a]++;
    }
    if(0){
    // if(b1 == 0){
    //     if(!uma[0]){
    //         cout<<"inf";
    //     }else{
    //         cout<<0;
    //     }
    // }else if(q == 0){
    //     int ans = 0;
    //     if(!uma[0]){
    //         cout<<"inf";
    //     }else{
    //         if(!uma[b1]){
    //             cout<<1;
    //         }else{
    //             cout<<0;
    //         }
    //     }
    // }else if(q == 1){
    //     if(uma[b1]){
    //         cout<<0;
    //     }else{
    //         cout<<"inf";
    //     }
    // }else if(q == -1){
    //     int ans = 0;
    //     if(!uma[b1]){
    //         ans++;
    //     }
    //     if(!uma[-b1]){
    //         ans++;
    //     }
    //     if(ans != 0){
    //         cout<<"inf";
    //     }else{
    //         cout<<ans;
    //     }
    }else{
        long long nas = 0;
        long long ans = 0;
        while(fabs(b1) <= l){
            nas++;
            if(!uma[b1]){
                ans++;
            }
            if(nas > 10000){
                if(ans == 0){
                    cout<<0;
                }else if(ans == 1){
                    cout<<1;
                }else{
                    cout<<"inf";
                }
                return 0;
            }
            b1 *= q;
        }
        cout<<ans;
    }
    return 0;
}