#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[100005];
long long coun[100005];

int find(int n){
    if(a[n] == n){
        return n;
    }
    return a[n] = find(a[n]);
}

struct edge{
    int x,y;
    int length;
    bool operator < (struct edge e){
        return this->length < e.length;
    }
};

struct edge e[100005];

void _union(int x,int y){
    int fx = find(x);
    int fy = find(y);
    a[fx] = fy;
    coun[fy] += coun[fx];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 1; i<=n ; i++){
        a[i] = i;
        coun[i] = 1;
    }
    int a,b,c;
    for(int i = 0; i<n-1 ; i++){
        cin>>a>>b>>c;
        e[i].x = a;
        e[i].y = b;
        e[i].length = c;
    }
    long long ans = 0;
    sort(e,e+n-1);
    for(int i = 0; i<n -1; i++){
        int fx = find(e[i].x);
        int fy = find(e[i].y);
        ans += ((long long)coun[fx] * coun[fy] - 1) * (e[i].length+1);
        _union(fx,fy);
    }
    cout<<ans;
    return 0;
}