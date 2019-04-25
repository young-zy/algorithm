#include<bits/stdc++.h>

using namespace std;

int a[10] = {2,4,6,8,10,12,14,16,18};
int b[10] = {3,5,7,9,11,13,15,17,19};
int n;

int isPrime(int a){
    if(a == 2 || a == 3){
        return 1;
    }else if(a < 2 || a % 2 == 0){
        return 0;
    }else{
        for(int i = 3; i<= sqrt(a); i+=2){
            if(a % i == 0){
                return 0;
            }
        }
        return 1;
    }
}

int dfs(int flaga[],int flagb[],int depth,int res[]){
    if(depth == n){
        if(isPrime(res[0]+res[n-1])){
            for(int i = 0 ; i< n ; i ++){
                if(i != 0){
                    cout<<" ";
                }
                cout<<res[i];
            }
            cout<<endl;
        }
    }else if(depth % 2){
        for(int i = 0; i< n/2;i++){
            if(flaga[i] == 0 && isPrime(res[depth-1] + a[i])){
                flaga[i] = 1;
                res[depth] = a[i];
                dfs(flaga,flagb,depth+1,res);
                flaga[i] = 0;
            }
        }
    }else{
        for(int i = 0; i< n/2-1;i++){
            if(flagb[i] == 0 && isPrime(res[depth-1] + b[i])){
                flagb[i] = 1;
                res[depth] = b[i];
                dfs(flaga,flagb,depth+1,res);
                flagb[i] = 0;
            }
        }
    }
}

int main(){
    cin>>n;
    if(n % 2){
        cout<<"No";
        return 0;
    }
    int flaga[10] = {0};
    int flagb[10] = {0};
    int res[20] = {0};
    res[0] = 1;
    dfs(flaga,flagb,1,res);
    return 0;
}