#include<bits/stdc++.h>

using namespace std;

int input;
string a = "(";

void dfs(int lcount,int rcount){
    if(lcount == rcount){
        if(lcount == input){
            cout<<a<<endl;
            return;
        }
        a+="(";
        lcount++;
        dfs(lcount,rcount);
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
        a+=")";
        rcount++;
        dfs(lcount,rcount);
        a.pop_back();
        a.pop_back();
    }
}

int main(){
    cin>>input;
    dfs(1,0);
    
    return 0;
}