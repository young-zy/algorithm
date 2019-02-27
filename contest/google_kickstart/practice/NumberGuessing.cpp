#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    string result = "";
    for(int i = 0; i <t; i++){
        long long a,b,n;
        cin>>a>>b;
        long times;
        cin>>times;
        while(times){
            long long c = (a+b)/2;
            if(c == a){
                c++;
            }
            cout<<c<<endl;
            fflush(stdout);
            cin>>result;
            if(result == "TOO_BIG"){
                b = (a+b)/2;
            }else if(result == "TOO_SMALL"){
                a = (a+b)/2;
            }else if(result == "CORRECT" || result == "WRONG_ANSWER"){
                break;
            }
            times--;
        }
    }
    return 0;
}