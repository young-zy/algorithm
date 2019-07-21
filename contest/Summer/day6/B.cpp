#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    int x;
    int y;
    bool operator < (struct node n) const {
        if(x == n.x){
            return y < n.y;
        }
        return x<n.x;
    }
};

struct node a[3005];

map<struct node,int> ma;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i<n ; i++){
        cin>>a[i].x>>a[i].y;
        ma[a[i]]++;
    }
    sort(a,a+n);
    long long count = 0;
    for(int i = 0; i< n-1;i++){
        for(int j = i+1;j<n;j++){
            struct node temp;
            if((a[i].x+a[j].x) % 2 || (a[i].y+a[j].y) % 2){
                continue;
            }
            temp.x = (a[i].x+a[j].x)/2;
            temp.y = (a[i].y+a[j].y)/2;
            if(ma[temp]){
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}