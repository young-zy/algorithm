#include<iostream>
#include<math.h>
#include<float.h>
// #include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0 ; te < t; te++){
        int a,b,c,n;
        cin>>a>>b>>c>>n;
        double avg = (a+b+c+n)/3.0;
        if( (avg < a || avg<b || avg<c) || fabs(avg - floor(avg))>DBL_EPSILON ){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}