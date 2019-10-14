#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    long long flag = 0;
    string temp;
    s+="a";
    long long ans = 0;
    int flag0 = 0;
    for(int i = 0 ;i < s.length();i++){
        if(s[i] == '.' || s[i] >= '0' && s[i] <='9'){
            if(!flag){
                flag = 1;
            }
            temp += s[i];
        }else{
            if(flag){
                flag = 0;
                long long count = 0;
                double base = 100;
                long long temp2 = 0;
                if(temp.length() >= 3 && temp[temp.length()-3]=='.'){
                    flag0 =1;
                    base = 1;
                    temp2 = 3;
                    ans += (temp[temp.length()-1]-'0')*0.01;
                    ans += (temp[temp.length()-2]-'0')*0.1;
                }
                for(int j = temp.length()-1; j>=0 ; j--){
                    if(temp[j] == '.'){
                        //count++;
                        continue;
                    } 
                    ans += (temp[j]-'0')*base;
                    base*=10;
                }
                temp = "";
            }
        }
    }
    string ans1;
    long long flag1 = 0;
    long long count = 0;
    while(ans){
        if(flag1 == 0 && count == 2){
            count = 0;
            flag1 = 1;
            ans1.insert(0,1,'.');
        }
        if(flag1 == 1 && count == 3){
            count = 0;
            ans1.insert(0,1,'.');
        }
        long long temp = ans%10;
        ans /= 10;
        ans1.insert(0,1,temp+'0');
        count++;
    }
    if(ans1.length()<4){
        long long temp = ans1.length();
        for(int i = 0; i<2-temp;i++){
            ans1.insert(0,1,'0');
        }
        ans1.insert(0,1,'.');
        ans1.insert(0,1,'0');
    }
    if(ans1[ans1.length()-1] == '0' && ans1[ans1.length()-2] == '0' && ans1[ans1.length()-3] == '.'){
        ans1=ans1.substr(0,ans1.length()-3);
    }
    cout<<ans1;
    return 0;
}