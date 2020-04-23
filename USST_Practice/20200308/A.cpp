#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n < 21){
        cout<< -1;
    }else{
        int time = n / 14;
        int mod = n % 14;
        if(mod < 2 || mod > 12){
            cout<<-1;
        }else{
            if(time == 1 && mod != 7){
                cout<< -1;
            }else{
                cout<<time;
            }
        }
    }
    return 0;
}