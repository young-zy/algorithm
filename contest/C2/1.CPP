#include<bits/stdc++.h>

using namespace std;

int main(){
    for(int i = sqrt(1000); i*i <=9999;i++){
        int temp = i*i;
        int a[4];
        int j = 0;
        while(temp != 0){
            a[j]=temp % 10;
            temp/=10;
            j++;
        }
        if(a[0] == a[1] && a[2] == a[3]){
            cout<<i*i;
        }
    }
    return 0;
}