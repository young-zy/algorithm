#include<bits/stdc++.h>

using namespace std;



long gugu(long c);

int main(){
    long q;
    long a[1500];
    memset(a,0,sizeof(a));
    cin>>q;
    long i = 2;
    while(!a[i]){
        a[i] = 1;
        long temp = gugu(i);
        i = temp;
    }
    for(long i = 0; i<q;i++){
        long k;
        cin>>k;

    }
    return 0;
}

long gugu(long c){
    long result = 0;
    while(c != 0){
        int temp = c % 10;
        c /= 10;
        result += temp *temp;
    }
    return result;
}