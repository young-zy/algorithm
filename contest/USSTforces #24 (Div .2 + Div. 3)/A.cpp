#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    int c[3] = {0};
    for(int i = 1; i<=6;i++){
        if(fabs(a-i) == fabs(b-i)){
            c[1]++;
        }else if(fabs(a-i) < fabs(b-i)){
            c[0]++;
        }else{
            c[2]++;
        }
    }
    cout<<c[0]<<" "<<c[1]<<" "<<c[2];
    return 0;
}