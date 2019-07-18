#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long dp[1005] = {0};

int prime[1005] = {0};

// bool is_Prime(int n){
//     if(n == 2 || n == 3){
//         return true;
//     }else if(n % 2 == 0 || n < 2){
//         return false;
//     }else{
//         for(int i =3; i<=sqrt(n) ; i+=2){
//             if(n % i == 0){
//                 return false;
//             }
//         }
//         return true;
//     }
// }

void Prime(){
    for(int i = 2; i<= 500 ;i++){
        if(!prime[i]){
            for(int j = 2;i*j <= 1000;j++){
                prime[i*j] = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Prime();
    int n;
    cin>>n;
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 2; i<=n;i++){
        if(!prime[i]){
            for(int j = i; j<=n ; j++){
                dp[j] += dp[j-i];
            }
        }
    }
    cout<<dp[n];
    return 0;
}