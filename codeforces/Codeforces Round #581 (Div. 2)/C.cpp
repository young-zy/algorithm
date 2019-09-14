#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[1000005];

string s[105];

int p[105][105][105];
int d[105][105];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    memset(p,0,sizeof(p));
    for(int i = 0; i<n ; i++){
        cin>>s[i];
    }
    memset(d,0x3f,sizeof(d));
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=n ; j++){
            if(s[i-1][j-1] == '1'){
                d[i][j] = 1;
            }
        }
    }
    int m;
    cin>>m;
    for(int i =0 ; i<m; i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){ 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == j){
                    continue;
                }
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j][k] = 1;
                }
            }
        }
    }
    int start = 0;
    int mid = 1;
    int end = 2;
    vector<int> ans;
    ans.push_back(a[start]);
    while(start <= m-2){
        ans.push_back(a[mid]);
        if(p[a[start]][a[end]][a[mid]]){
            ans.pop_back();
            mid= end;
            end++;
        }else{
            start = mid;
            mid = end;
            end++;
        }
    }
    cout<<ans.size()<<endl;
    for(int i = 0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}