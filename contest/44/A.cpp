#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,y,dx,dy;
    cin>>t>>n>>x>>y>>dx>>dy;
    if(x == t || y == t || x + y == t){
        cout<<"YES";
        return 0;
    }
    if(x < t && y < t){
        if(x + y  < t){
            cout<<"NO";
            return 0;
        }else{
            int sum = x+y;
            for(int i = 0; i<n ; i++){
                for(int j = 0; j<n ; j++){
                    if(sum - i*dx - j*dy == t){
                        cout<<"YES";
                        return 0;
                    }
                }
            }
            cout<<"NO";
            return 0;
        }
    }else{
        if(x >= t && x % dx == 0 && x/dx < n){
            cout<<"YES";
            return 0;
        }
        if(y >= t && y %dy == 0 && y/dy < n){
            cout<<"YES";
            return 0;
        }
        int sum = x+y;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<n ; j++){
                if(sum - i*dx - j*dy == t){
                    cout<<"YES";
                    return 0;
                }
            }
        }
        cout<<"NO";
        return 0;
    }
    return 0;
}