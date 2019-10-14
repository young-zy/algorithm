#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double p,d,t,f,c;
    cin>>p>>d>>t>>f>>c;
    double t1 = 0;
    long long ans =0;
    while(t *p < c){
        if(d-p<=0){
            break;
        }
        t1 = (t*p)/(d-p);
        if((t+t1)*p>=c){
            break;
        }
        ans++; 
        t = t+2*t1+f;
    }
    cout<<ans;
    return 0;
}