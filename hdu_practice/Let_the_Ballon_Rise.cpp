#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    while(1){
        scanf("%d",&num);
        if(num == 0){
            break;
        }
        map<string,int> m;
        for(int i = 0;i<num;i++){
            string temp;
            cin>>temp;
            if(m.find(temp)->second == 0){
                m[temp] = 1;
            }else{
                m[temp]++;
            }
        }
        map<string,int>::iterator it;
        map<string,int>::iterator itmax = m.begin();
        for(it = m.begin();it!=m.end();it++){
            if(it->second > itmax->second){
                itmax = it;
            }
        }
        cout<<itmax->first<<endl;
    }    
    return 0;
}