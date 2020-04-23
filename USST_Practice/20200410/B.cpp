#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int a[4];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int flag=1;
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]){
        if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && a[3] ==0){
            break;
        }
        if(flag){
            flag = 0;
        }else{
            cout<<endl<<endl;
        }
        sort(a, a+4);
        int i = 24;
        int flag2 = 1;
        int flag3 = 0;
        int b[4];
        while(a[0] == 0){
            next_permutation(a,a+4);
        }
        int last = a[0];
        for(int i = 0; i<4;i++){
            b[i] = a[i];
        }
        while(i--){
            if(flag3){
                if(a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3]){
                    break;
                }
            }else{
                flag3 = 1;
            }
            if(a[0] != 0 && a[0] != last){
                last = a[0];
                cout<<endl;
                flag2 = 1;
            }
            if(a[0]!=0){
                if(flag2){
                    flag2 = 0;
                }else{
                    cout<<" ";
                }
                cout<<a[0]<<a[1]<<a[2]<<a[3];
            }
            next_permutation(a,a+4);
        }
        
    }
    return 0;
}