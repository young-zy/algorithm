#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

string ch[105];

long long a[105][105][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    for(int i = 0; i<n; i++){
        cin>>ch[i];
    }
    int maxx = 0;
    int maxy = 0;
    int maxnum = 0;
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<n ; j++)
        {
            if(ch[i][j] == '#'){
                a[i][j][0] = 0;
                a[i][j][1] = 0;
                continue;
            }
            int ansa = 0;
            int ansb = 0;
            int len;
            len = 0;
            while(i-len-1>=0 && len<k-1 && ch[i-len-1][j] != '#'){
                len++;
            }
            ansa += len;
            len = 0;
            while(i+len+1<=n-1 && len<k-1 && ch[i+len+1][j] != '#'){
                len++;
            }
            ansa += len;
            len = 0;
            while(j-len-1>=0 && len<k-1 && ch[i][j-len-1] != '#'){
                len++;
            }
            ansb += len;
            len = 0;
            while(j+len+1<=n-1 && len<k-1 && ch[i][j+len+1] != '#'){
                len++;
            }
            ansb += len;
            a[i][j][0] = ansa+1;
            a[i][j][1] = ansb+1;
            int ans = 0;
            ans += max(0,ansa+2-k);
            ans += max(0,ansb+2-k);
            if(ans > maxnum){
                maxnum = ans;
                maxx = i;
                maxy = j;
            }
        }
    }
    cout<<maxx+1<<" "<<maxy+1;
    return 0;
}