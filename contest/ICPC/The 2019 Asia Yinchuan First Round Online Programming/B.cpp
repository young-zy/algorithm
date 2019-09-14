#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int a[55][2];

double angel(int x1,int y1,int x2,int y2,int x3,int y3){
    long double k1 = (long double)(y2-y1)/(x2-x1);
    long double k2 = (long double)(y3-y2)/(x3-x2);
    if(k2 == INFINITY || k2 == -INFINITY){
        k2 = 999999999;
    }
    if(k1 == INFINITY || k1 == -INFINITY){
        k1 = 999999999;
    }
    long double temp = (k2-k1)/(1+k1*k2);
    long double t = atan(temp);
    if(t < 0){
        t = 3.14159265358979323846264338327950288+t;
    }
    return t;
}

long double dist(int x1,int y1,int x2,int y2){
    long double a = x1-x2;
    a *= a;
    double b = y1-y2;
    b *= b;
    a+= b;
    return sqrt(a);
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0 ; te < t ; te++){
        int n;
        int x,y;
        cin>>n;
        long double ans = 0;
        for(int i = 0; i<n; i++){
            cin>>a[i][0]>>a[i][1];    
        }
        cin>>x>>y;
        for(int i = 0; i<n-2 ; i++){
            long double ang = angel(a[i][0],a[i][1],a[i+1][0],a[i+1][1],a[i+2][0],a[i+2][1]);
            long double dis = dist(a[i+1][0],a[i+1][1],x,y);
            ans += dis * ang;
        }
        long double ang = angel(a[n-2][0],a[n-2][1],a[n-1][0],a[n-1][1],a[0][0],a[0][1]);
        long double dis = dist(a[n-1][0],a[n-1][1],x,y);
        ans += dis * ang;
        ang = angel(a[n-1][0],a[n-1][1],a[0][0],a[0][1],a[1][0],a[1][1]);
        dis = dist(a[0][0],a[0][1],x,y);
        ans += dis * ang;
        
        printf("Case #%d: %.3Lf\n",te+1,ans);
    }
    return 0;
}