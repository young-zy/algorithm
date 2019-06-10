#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long num;
int flag = 0;
long long maximum = (1LL<<32)-1;

void f(string a){
    if(flag == 1){
        return;
    }
    while(a != "end"){
        if(a == "add"){
            num = (num + 1)*num/2;
            if(num > maximum){
                flag = 1;
                return;
            }
        }
        if(a == "for"){
            int loopnum;
            cin>>loopnum;
            cin>>a;
            for(int i = 0; i< loopnum;i++){
                f(a);
            }
        }
        if(a == "end"){
            return;
        }
        cin>>a;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin>>num;
    cin>>a;
    f(a);
    if(flag == 0){
        cout<<num;
    }else{
        cout<<"OVERFLOW!!!";
    }
    
    return 0;
}