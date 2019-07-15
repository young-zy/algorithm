#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define MOD 99037660

using namespace std;

long long a[4][4] = {
                    {1,0,1,1},
                    {1,0,0,0},
                    {0,1,0,0},
                    {0,0,1,0}
                    };

struct s{
    long long b[4][4];
    s(){
        for(int i = 0; i<4;i++){
            for(int j = 0; j< 4; j++){
                b[i][j] = a[i][j];
            }
        }
    }
};

struct s operator * (struct s _1,struct s _2){
    struct s temp;
    for(int i = 0; i<4 ; i++){
        for(int j = 0; j< 4; j++){
            temp.b[i][j] = 0;
        }
    }
    for(int i = 0; i<4;i++){
        for(int j = 0; j< 4; j++){
            for(int k = 0; k< 4;k++){
                temp.b[i][j] += _1.b[i][k] * _2.b[k][j] % MOD;
                temp.b[i][j] %= MOD;
            }
        }
    }
    return temp;
}

struct s fast(long long n){
    struct s ans;
    for(int i = 0; i<4;i++){
        for(int j = 0; j<4;j++){
            if(i == j){
                ans.b[i][j] = 1;
            }else{
                ans.b[i][j] = 0;
            }
        }
    }
    struct s s1 = s();
    while(n){
        if(n & 1){
            ans = ans * s1;
        }
        s1 = s1*s1;
        n >>= 1;
    }
    return ans;
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    long long ans = 0;
    long long a[4] = {9,6,4,2};
    if(n == 0){
        ans = 0;
    }else if(n <= 4){
        ans = a[-(n-4)];
    }else{
        struct s temp = fast(n-4);
        for(int i = 0; i<4 ; i ++){
            ans = ans + temp.b[0][i] * a[i];
            ans %= MOD;
        }
    }
    
    cout<<ans;
    return 0;
}