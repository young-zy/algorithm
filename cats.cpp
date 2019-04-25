#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[3];
    int k = 0;
    while(n){
        a[k] = n % 10;
        n /= 10;
        k++;
    }
    return 0;
}