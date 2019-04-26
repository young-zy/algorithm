#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,d;
    long long count = 0;
    cin>>a>>b>>c>>d;
    long long x[4];
    long long y[4];
    x[0] = b-a+1;
    x[1] = b/2-(a-1)/2;
    x[2] = b/1009-(a-1)/1009;
    x[3] = b/2018 - (a-1)/2018;
    x[2] -= x[3];
    x[1] -= x[3];
    x[0] -= x[1] +x[2]+x[3];
    y[0] = d-c+1;
    y[1] = d/2-(c-1)/2;
    y[2] = d/1009-(c-1)/1009;
    y[3] = d/2018 - (c-1)/2018;
    y[2] -= y[3];
    y[1] -= y[3];
    y[0] -= y[1] +y[2]+y[3];
    count += x[1] * y[2];
    count += x[1] * y[3];
    count += x[2] * y[1];
    count += x[2] * y[3];
    count += x[3] * y[1];
    count += x[3] * y[2];
    count += x[3] * y[3];
    count += x[0] * y[3];
    count += x[3] * y[0];

    cout<<count;
    return 0;
}