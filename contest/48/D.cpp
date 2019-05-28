#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sum;
    cin>>sum;
    map<int,int> ma;
    int count = -1;
    for(int i = sum/8; i>=0;i--){
        if((sum -i*8) % 5 ==0 ){
            count = i;
            break;
        }
    }
    if(count == -1){
        cout<<count;
        return 0;
    }else{
        for(int i = 0; i<(sum -count*8) / 5;i++ ){
            cout<<5;
        }
        for(int i = 0; i< count;i++){
            cout<<8;
        }
    }

    return 0;
}