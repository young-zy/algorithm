#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    while(cin>>a){
        int flag = 0;
        map<char,int> ma;
        for(int i = 0; i< a.length();i++){
            // if(flag == 0 && (a[i] == 'S' || a[i] == 's')){
            //     flag++;
            // }else{
            //     flag = 0;
            // }
            // if(flag == 1 && (a[i] == 'i' || a[i] == 'I')){
            //     flag++;
            // }else{
            //     flag = 0;
            // }
            // if(flag == 2 && (a[i] = 'w' || a[i] =='W')){
            //     flag++;
            // }else{
            //     flag = 0;
            // }
            // if(flag == 3){
            //     flag = 0;
            //     cout<<"SIW";
            // }
            if(a[i] >='a' && a[i] <='z'){
                a[i] = a[i]+'A'-'a'; 
            }
            ma[a[i]]++;
        }
        flag = 0;
        int count = 1;
        while(count){
            count = 0;
            if(ma['S']){
                cout<<"S";
                ma['S']--;
                count++;
            }
            if(ma['I']){
                cout<<"I";
                ma['I']--;
                count++;
            }
            if(ma['W']){
                cout<<"W";
                ma['W']--;
                count++;
            }
        }
        cout<<endl;
    }
    return 0;
}