#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    while(1){
        scanf("%d",&num);
        if(num == 0){
            break;
        }else{
            map<int,int> m;
            for(int i = 0;i< num;i++){
                int temp;
                scanf("%d",&temp);
                m[temp]++;
            }
            map<int,int>::iterator it;
            for(it = m.begin();it!=m.end();it++){
                if(it->second == 1){
                    cout<<it->first<<endl;
                }
            }
        }
    }
    return 0;
}