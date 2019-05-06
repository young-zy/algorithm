#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

struct node{
    int base;
    int times;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n == 1){
        cout<<1;
        return 0;
    }
    long long res = 1;
    for(int i = 2; i<=n;i++){
        int count = 0;
        while(n % i == 0){
            count ++;
            n /= i;
        }
        if(count > 0){
            res *= pow(i,count-1);
            res *= i-1;
        }
    }
    cout<<res;
    return 0;
}