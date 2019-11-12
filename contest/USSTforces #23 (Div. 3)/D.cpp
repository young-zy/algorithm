#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[2][200005];



int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int q;
    cin>>q;
    for(int qe = 0; qe< q; qe++){
        int n;
        cin>>n;
        for(int i = 0; i<n ; i++){
            scanf(" %c",&a[0][i]);
            a[0][i] -= '0';
        }
        for(int i = 0; i<n ; i++){
            scanf(" %c",&a[1][i]);
            a[1][i] -= '0';
        }
        int flag = 1;
        int x = 0,y=0;
        while(y < n){
            if(a[x][y] == 1 || a[x][y] == 2){
                y++;
            }else{
                if(x == 0){
                    if(a[1][y] == 1 || a[1][y] == 2){
                        flag = 0;
                        break;
                    }else{
                        x = 1;
                        y ++;
                    }
                }else{
                    if(a[0][y] == 1 || a[0][y] == 2){
                        flag = 0;
                        break;
                    }else{
                        x = 0;
                        y ++;
                    }
                }
            }
        }
        if(flag && x == 1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}