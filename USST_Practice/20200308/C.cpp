#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int flag[13]; //0-9,--, up, down
int a[100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(a,0x3f,sizeof(a));
    memset(flag, 0 ,sizeof(flag));
    for(int i = 1; i < 4;i++){
        cin>>flag[i];
    }
    cin>>flag[11];
    for(int i = 4; i < 7;i++){
        cin>>flag[i];
    }
    cin>>flag[12];
    for(int i = 7; i< 10;i++){
        cin>>flag[i];
    }
    cin>>flag[10]>>flag[0];
    int from, to;
    cin>>from>>to;
    for(int i = 0; i<10;i++){
        if(flag[i]){
            a[i] = 1;
        }
    }
    if(flag[10]){
        for(int i = 10; i<=99 ;i++){
            int b,c;
            b = i/10;
            c = i%10;
            if(flag[b] && flag[c]){
                a[i] = 3;
            }
        }
    }
    a[from] = 0;
    while(flag[11]){
        int fl = 0;
        for(int i = 0; i < 100;i++){
            if(i == 0){
                if(a[i] > a[99]+1){
                    fl = 1;
                    a[i] = a[99]+1;
                }
            }else{
                if(a[i] > a[i-1]+1){
                    fl = 1;
                    a[i] = a[i-1]+1;
                }
            }
        }
        if(fl == 0){
            break;
        }else{
            fl = 0;
        }
    }
    while(flag[12]){
        int fl = 0;
        for(int i = 99; i >= 0;i--){
            if(i == 99){
                if(a[i] > a[0]+1){
                    fl = 1;
                    a[i] = a[0]+1;
                }
            }else{
                if(a[i] > a[i+1]+1){
                    fl = 1;
                    a[i] = a[i+1]+1;
                }
            }
        }
        if(fl == 0){
            break;
        }else{
            fl = 0;
        }
    }
    if(a[to] >= INF){
        a[to] = -1;
    }
    cout<<a[to];
    return 0;
}