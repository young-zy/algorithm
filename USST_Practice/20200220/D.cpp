#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i<n ; i++){
        int k;
        cin>>k;
        double res = 0;
        for(int i = 1; i<=k ; i++){
            res += log10(i);
        }
        int resi = ceil(res);
        cout<<resi<<endl;
    }
    return 0;
}