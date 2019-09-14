#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    set<int> ser,sec;
    int r,c;
    r = n;
    c = n;
    while(q--){
        char ch;
        int num;
        cin>>ch>>num;
        if(ch == 'R'){
            int temp = ser.size();
            ser.insert(num);
            if(ser.size() == temp)
                cout<<0<<endl;
            else{
                cout<<r--<<endl;
            }
        }else{
            int temp = sec.size();
            sec.insert(num);
            if(sec.size() == temp)
                cout<<0<<endl;
            else{
                cout<<c--<<endl;
            }
        }
    }
    return 0;
}