#include<iostream>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    if(a.length() < b.length()){
        swap(a,b);
    }
    int flag = 0;
    string res;
    int i;
    int c = a.length()-b.length();
    for(i = b.length()-1; i >=0; i--){
        int temp = a[i+c]-'0'+b[i]-'0'+flag;
        flag = 0;
        if(temp >= 10){
            flag = 1;
            temp -=10;
        }
        res.insert(0,1,'0'+temp);
    }
    while(c--){
        int temp = flag + a[c] - '0';
        flag = 0;
        if(temp > 10){
            temp -= 10;
            flag = 1;
        }
        res.insert(0,1,temp+'0');
        flag = 0;
        i++;
    }
    if(flag == 1){
        res.insert(0,1,'1');
    }
    cout<<res;
    return 0;
}