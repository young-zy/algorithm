#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    while(~scanf("%d",&k)){
        if(k % 2){
            printf("0\n");
        }else{
            printf("1\n");
        }
    }
    return 0;
}