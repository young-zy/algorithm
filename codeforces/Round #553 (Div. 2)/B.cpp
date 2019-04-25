#include<bits/stdc++.h>

using namespace std;

int a[500][500];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    if(n == 1){
        cout<<"TAK"<<endl<<"1";
        return 0;
    }
    int res[n+1];
    int flag = 1;
    for(int i = 0; i< n ; i++){
        map<int,int> ma;
        for(int j = 0; j< m ;j++){
            scanf("%d",&a[i][j]);
            ma[a[i][j]]++;
        }
        if(i == 0){
            if(ma[0] > 0){
                flag = 0;
                break;
            }
        }else{
            auto it = --ma.end();
            if(ma.size() == m  && it->first == m && ma[0] == 0){
                flag = 0;
                break;
            }else{
                for(int j = 1;i <= m;j++){
                    if(ma[j] == 0){
                        res[i] = j;
                        break;
                    }
                }
            }
        }
    }
    res[n] = 3;
    if(flag == 0){
        cout<<"NIE";
    }else{
        cout<<"TAK"<<endl;
        for(int i = 1; i<= n; i++){
            cout<<res[i]<<" ";
        }
    }
    return 0;
}