#include<bits/stdc++.h>

using namespace std;

int sum[200005],ans[200005],f[200005];

main(){
    int n,m,l;
    cin>>n>>m>>l;
    memset(ans,0,sizeof(ans));
    memset(f,0,sizeof(f));
    for(int i = 0; i<n;i++){
        int a,b;
        cin>>a>>b;
        if(b>l){
            continue;
        }
        f[max(a+b-l,0)]++;
        f[min(a+l-b+1,200001)]--;
    }
    ans[0] = f[0];
    for(int i = 1; i<=200005;i++){
        ans[i] = ans[i-1]+f[i];
    }
    for(int i = 1;i<=m;i++){
        int temp;
        cin>>temp;
        cout<<ans[temp]<<endl;
    }

    return 0;
}