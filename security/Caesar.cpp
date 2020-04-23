#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

string encrypt(int k, string st);

string decrypt(int k, string st);

int main(){
    int mode = 0;
    cout<< "请输入模式：\n1. 加密\n2. 解密\n";
    cin>>mode;
    int k;
    string s;
    cout<<"请输入密钥";
    cin>>k;
    if(mode == 1){
        cout<<"请输入明文：";
    }else if(mode == 2){
        cout<<"请输入密文：";
    }
    getchar();
    getline(cin, s);
    string res;
    if(mode == 1){
        cout<<"密文为：";
        res = encrypt(k,s);
    }else if(mode == 2){
        cout<<"明文为：";
        res = decrypt(k,s);
    }
    cout<<res;
    return 0;
}

string encrypt(int k, string st){
    int i = 0;
    string s = st;
    while(i < s.length()){
        if(s[i] >='a' && s[i] <= 'z'){
            s[i] = s[i] - 26 + k;       //预先-26防止溢出
            if(s[i] < 'a'){
                s[i] += 26;
            }
        }else{
            s[i] += k;
            if(s[i] > 'Z'){
                s[i] -= 26;
            }
        }
        i++;
    }
    return s;
}

string decrypt(int k, string st){
    int i = 0;
    int j = 0;
    string s = st;
    while(i < s.length()){
        if(s[i] >='a' && s[i] <= 'z'){
            s[i] -= k;
            if(s[i] < 'a'){
                s[i] += 26;
            }
        }else{
            s[i] -= k;
            if(s[i] < 'A'){
                s[i] += 26;
            }
        }
        i++;
    }
    return s;
}