#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

struct node {
    long double x,r;
    bool operator < (node b){
        return this->x < b.x;
    }
    int index;
};

bool cmp(node n1,node n2){
    return n1.index < n2.index;
}

node no[10005];

long double dist(long double x1,long double y1,long double x2,long double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int ans[10005];
int les[42005];
int mor[42005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    memset(ans,-1,sizeof(ans));
    for(int i = 0; i<n ; i++){
        cin>>no[i].x>>no[i].r;
        no[i].index = i;
    }
    sort(no,no+n);
    int in1 = 0;
    int in2 = 0;
    for(int i = 0; i<=42000;i++){
        if(i-21000 < no[in1].x){
            mor[i] = in1;
        }else{
            while( in1 < n-1 && i-21000 > no[in1].x){
                in1++;
            }
            mor[i] = in1;
        }
        if(i-21000 <= no[in2+1].x){
            les[i] = in2;
        }else{
            if(in2 == n-2 && i-21000 > no[in2-1].x){
                in2++;
            }
            while(in2 < n-2 && i-21000 > no[in2+1].x){
                in2++;
            }
            les[i] = in2;
        }
    }
    int m;
    cin>>m;
    int count = 0;
    for(int i = 0; i<m ; i++){
        int x,y;
        cin>>x>>y;
        int l = les[x+21000];
        int r = mor[x+21000];
        long double d1 = dist(x,y,no[l].x,0);
        long double d2 = dist(x,y,no[r].x,0);
        if(ans[no[l].index] == -1 && d1 - no[l].r <=__LDBL_EPSILON__){
            ans[no[l].index] = i+1;
            count++;
        }
        if(ans[no[r].index] == -1 && d2 - no[r].r <=__LDBL_EPSILON__){
            ans[no[r].index] = i+1;
            count++;
        }
    }
    cout<<count<<endl;
    for(int i = 0; i<n ; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}