#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

unsigned long long T(long long n){
    return n*(n+1)/2;
}

unsigned long long P(long long n){
    return n*(3*n-1)/2;
}

unsigned long long H(long long n){
    return n*(2*n-1);
}

unordered_map<long long,int> uma;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 2; i<100000;i++){
        long long t = T(i);
        long long p = P(i);
        long long h = H(i);
        uma[t]++;
        uma[p]++;
        uma[h]++;
        // if(i == 285){
        //     system("pause");
        //     cout<<uma[40755];
        // }
        if(uma[t] == 3 && t>40755){
            cout<<t;
            break;
        }
    }
    //cout<<1533776805;
    return 0;
}