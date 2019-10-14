#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

const long long mod = 1000000007;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FILE *fp = fopen("out.txt","w+");
    unsigned long long a,b;
    while(cin>>a>>b){
        b %= mod;
        fprintf(fp,"%llu,",b);
    }
    return 0;
}