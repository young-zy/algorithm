#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int x;
int flag = 0;
map<int ,int> ma;

void dfs(int sum,int num){
    if(flag == 1 || sum > 150-x){
        return ;
    }
    if(sum == 150 - x){
        flag = 1;
        cout<<num<<endl;
        return ;
    }
    for(map<int,int>::reverse_iterator it = ma.rbegin(); it != ma.rend();it++){
        if(flag == 1){
            return;
        }
        if(it->second > 0){
            it->second --;
            dfs(sum+it->first,num+1);
            it->second++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0;i<=150;i++){
        if(i == 0){
            cout<<i<<": "<<21<<endl;
        }else if(i < 4){
            cout<<i<<": "<<-1<<endl;
        }else{

        }
    }
    return 0;
}