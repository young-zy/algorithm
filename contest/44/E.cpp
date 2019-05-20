#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int m,k;
    cin>>n>>m>>k;
    int count =0;
    for(int i = 0; i<n ; i++){
        int flag = 0;
        for(int i =0; i<m ; i++){
            int temp = 0;
            cin>>temp;
            if(flag == 0 && temp == k){
                count ++;
                flag++;
            }
        }
    }
    cout<<n - count;
    return 0;
}