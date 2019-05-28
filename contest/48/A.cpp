#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int x;
int flag = 0;
map<int ,int> ma;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    for(int te = 0; te< t ; te++){
        flag = 0;
        cin>>x;
        int num = INF;
        if(x > 150){
            cout<<-1<<endl;
            continue;
        }
        for(int i = 0; i<= 6 ;i++){
            for(int j = 0; j<= 10;j++){
                for(int k = 0 ;k<=3;k++){
                    for(int l = 0; l <= 1;l++){
                        for(int m=0;m<=1;m++){
                            if(4*i + 5*j + 14*k + 16*l+18*m == 150-x){
                                num = min(num,i+j+k+l+m);
                            }
                        }
                    }
                }
            }
        }
        if(num == INF){
            cout<<-1<<endl;
        }else{
            cout<<num<<endl;
        }
    }
    return 0;
}