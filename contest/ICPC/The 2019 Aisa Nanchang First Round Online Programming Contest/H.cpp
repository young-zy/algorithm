#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define MOD 998244353

using namespace std;

unordered_map<long long, int> ma;


long long a[2][2] = {
                    {3,1},
                    {2,0},
                    };

struct s{
    long long b[2][2];
    s(){
        for(int i = 0; i<2;i++){
            for(int j = 0; j< 2; j++){
                b[i][j] = a[i][j];
            }
        }
    }
};

struct s operator * (struct s _1,struct s _2){
    struct s temp;
    for(int i = 0; i<2 ; i++){
        for(int j = 0; j< 2; j++){
            temp.b[i][j] = 0;
        }
    }
    for(int i = 0; i<2;i++){
        for(int j = 0; j< 2; j++){
            for(int k = 0; k< 2;k++){
                temp.b[i][j] += _1.b[i][k] * _2.b[k][j] % MOD;
                temp.b[i][j] %= MOD;
            }
        }
    }
    return temp;
}

struct s fast(long long n){
    struct s ans;
    for(int i = 0; i<2;i++){
        for(int j = 0; j<2;j++){
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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int q;
    long long n;
    cin>>q>>n;
    long long answer = -INF;
    
    while(q--){
        long long ans = 0;
        if(n == 0){
            ans = 0;
            ma[0] = 0;
        }else{
            if(ma[n]){
                ans = ma[n];
            }else{
                struct s temp = fast(n-1);
                ans += temp.b[0][0];
                ans %= MOD;
                ma[n] = ans;
            }   
        }
        n ^= ans*ans;
        if(answer == -INF){
            answer = ans;
        }else{
            answer ^= ans;
        }
        //cout<<q<<": "<<n<<" "<<ans<<endl;
    }
    cout<<answer;
    return 0;
}