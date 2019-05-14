#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int time;
    cin>>time;
    for(int j = 0; j< time;j++){
        long long i = 1;
        long long t;
        cin>>t;
        while(1){
            if(t <= i){
                if(t == 1){
                    cout<<1<<endl;
                }else{
                    cout<<0<<endl;
                }
                break;
            }
            t -= i;
            i++;
        }
    }
    return 0;
}