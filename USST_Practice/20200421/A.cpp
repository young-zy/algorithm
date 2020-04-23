#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

bool isPrime(int a){
    if(a == 2||a == 3){
        return true;
    }else if(a <2 || a%2 == 0){
        return false;
    }else{
        for(int i = 2; i<= sqrt(a); i++){
            if(a % i == 0){
                return false;
            }
        }
        return true;
    }
}

void dfs(int n, int index, int res[], int flag[]){
    if(index == n){
        if(isPrime(res[n-1]+1)){
            for(int i = 0; i< n; i++){
                if(i != 0){
                    cout<<" ";
                }
                cout<<res[i];
            }
            cout<<endl;
        }
        return;
    }
    for(int i = 2; i <= n ; i++){
        if(!flag[i] && isPrime(res[index-1] + i)){
            res[index] = i;
            flag[i] = 1;
            dfs(n,index+1, res, flag);
            flag[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int res[n];
    int flag[n+1];
    memset(flag,0,sizeof(flag));
    res[0] = 1;
    dfs(n,1,res,flag);
    return 0;
}