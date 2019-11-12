#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long p[200005];
int n;


long long calc(int n,int x,int a, int y,int b){
    long long ans = 0;
    int c = 0,d = 0,e = 0;
    for(int i = 1;i<=n;i++){
        if(i %a == 0 && i%b==0){
            e++;
        }else if(i %a == 0){
            c++;
        }else if(i % b == 0){
            d++;
        }
    }
    for(int i = 1; i<e+1;i++){
        ans += p[i]*(x+y);
    }
    for(int i = e+1 ;i < c+e+1;i++){
        ans += p[i]*x;
    }
    for(int i = c+e+1;i<c+d+e+1;i++){
        ans += p[i]*y;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    for(int qe = 0; qe< q;qe++){
        cin>>n;
        for(int i = 1; i<=n ; i++){
            cin>>p[i];
            p[i]/=100;
        }
        sort(p+1,p+n+1,greater<long long>());
        int x,a;
        cin>>x>>a;
        int y,b;
        cin>>y>>b;
        long long k;
        cin>>k;
        if(x<y){
            int temp = x;
            x = y;
            y = temp;
            temp = a;
            a = b; 
            b = temp;
        }
        //二分？
        int l = 0,r = n+1;
        while(r - l >1){
            int mid = (l+r)/2;
            if(calc(mid,x,a,y,b) >= k){
                r = mid;
            }else{
                l = mid;
            }
        }
        if(r > n){
            r = -1;
        }
        cout<<r<<endl;
    }
    return 0;
}