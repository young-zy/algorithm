#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n % 4 == 1){
        printf("0 A");
    }else if(n % 4 == 2){
        printf("1 B");
    }else if(n % 4 == 3){
        printf("2 A");
    }else if(n % 4 == 0){
        printf("1 A");
    }
    return 0;
}