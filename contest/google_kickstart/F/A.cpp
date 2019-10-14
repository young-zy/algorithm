#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[105];

unordered_map<int,int> uma;
vector<int> ve;

int dp[105][1005];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 1; te <= t ;te++){
        int n,k;
        cin>>n>>k;
        for(int i = 0; i<n ; i++){
            cin>>a[i];
            uma[a[i]]++;
        }
        int ans;
        // for(int i = n-1; i>=0 ; i--){
        //     for(int j= 1;j<=1000;j++){
        //         if(!uma[j]){
        //             continue;
        //         }
        //         if(a[i] == j){
        //             dp[i][j] = dp[i+1][j];
        //         }else{
        //             dp[i][j] = dp[i+1][]
        //         }
        //     }
        // }    
        int target = n-1;
        int lastcount = INF;
        while(1){
            int count = 0;
            for(int i = 0; i<n-target;i++){
                if(a[i] == a[i+target]){
                    for(int j = i+1; j<i+target ; j++){
                        if(a[j] == a[i]){
                            continue;
                        }else{
                            count++;
                        }
                    }
                }
            }
            int step = 0;
            for(int i = 0; i<n-1 ; i++){
                if(a[i] != a[i+1]){
                    step++;
                }
            }
            if(step>k){

            }else{
                lastcount = min(lastcount,count);
            }
            target--;
            if(target <=0){
                break;
            }
        }
        ans = lastcount;
        cout<<"Case #"<<te<<": "<<ans<<endl;
    }
    return 0;
}