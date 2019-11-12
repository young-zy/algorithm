#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[3][3];
int ans[3][3];
int b[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int max = 0;
    for(int i  =0; i<3 ;i++){
        int sum = 0;
        for(int j = 0; j<3;j++){
            cin>>a[i][j];
            sum += a[i][j];
        }
        b[i] = sum;
    }
    for(int s = 1; s<=300000 ;s++){
        int flag= 1;
        int ans[3][3];
        memcpy(ans,a,sizeof(a));
        for(int i = 0; i<3;i++){
            if(b[i] >= s){
                flag = 0;
                break;
            }
            ans[i][i] = s - b[i]; 
        }
        if(flag == 0){
            continue;
        }
        flag = 1;
        for(int j = 0; j<3;j++){
            int sum = 0;
            for(int i = 0; i<3;i++){
                sum += ans[i][j];
            }
            if(sum != s){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            if(ans[0][0] + ans[1][1] + ans[2][2] == s && ans[0][2] + ans[1][1] + ans[2][0] == s){
                for(int i = 0; i<3;i++){
                    for(int j = 0; j<3;j++){
                        cout<<ans[i][j]<<" ";
                    }
                    cout<<endl;
                }
                return 0;
            }
        }else{
            continue;
        }
    }
    return 0;
}