#include<bits/stdc++.h>

using namespace std;

int input;

void dfs(int lcount,int rcount,string a){
    if(lcount == rcount){
        if(lcount == input){
            cout<<a<<endl;
            return;
        }
        a+="(";
        lcount++;
        dfs(lcount,rcount,a);
        return;
    }
    if(lcount > rcount){
        if(lcount == input){
            for(int i = 0;i < lcount - rcount;i++){
                a+=")";
            }
            cout<<a<<endl;
            return;
        }
        dfs(lcount,rcount+1,a+")");
        dfs(lcount+1,rcount,a+"(");
        return;
    }
}

int main(){
    cin>>input;
    dfs(1,0,"(");
    
    return 0;
}