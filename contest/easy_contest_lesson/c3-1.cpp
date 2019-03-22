#include<bits/stdc++.h>

using namespace std;

int main(){
    for(int i = 33; i <= sqrt(9999);i++){
        int temp = i * i;
        int a[4];
        for(int j = 0; j< 4; j++){
            a[j] = temp % 10;
            temp /= 10;
        }
        if(a[0] == a[1] && a[2] == a[3]){
            cout<<i*i;
        }
    }
    return 0;
}