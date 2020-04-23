#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;


string encrypt(string k, string st);

string decrypt(string k, string st);

int main(){
    int mode = 0;
    cout<< "请输入模式：\n1. 加密\n2. 解密\n";
    cin>>mode;
    string s,k;
    getchar();
    cout<<"请输入密钥：";
    getline(cin, k);
    if(mode == 1){
        cout<<"请输入明文：";
    }else if(mode == 2){
        cout<<"请输入密文：";
    }
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

string encrypt(string k, string st){
    int i = 0;
    int j = 0;
    string s = st;
    while(i < s.length()){
        if(!(s[i] >= 'a' &&s[i]<='z' || s[i] >='A' &&s[i] <= 'Z')){
            i++;
            continue;
        }
        if(s[i] >='a' && s[i] <= 'z'){
            if(k[j] >= 'a' && k[j] <= 'z'){
                s[i] = s[i] - 26 + k[j]-'a';    //预先-26防止ascii溢出
            }else{
                s[i] = s[i] - 26 + k[j] - 'A' ;
            }
            if(s[i] < 'a'){
                s[i] += 26;
            }
        }else{
            if(k[j] >= 'a' && k[j] <= 'z'){
                s[i] += k[j]-'a';
            }else{
                s[i] += k[j] - 'A';
            }
            if(s[i] > 'Z'){
                s[i] -= 26;
            }
        }
        i++;
        j++;
        if(j >= k.length() ){
            j = 0;
        }
    }
    return s;
}

string decrypt(string k, string st){
    int i = 0;
    int j = 0;
    string s = st;
    while(i < s.length()){
        if(!(s[i] >= 'a' &&s[i]<='z' || s[i] >='A' &&s[i] <= 'Z')){
            i++;
            continue;
        }
        if(s[i] >='a' && s[i] <= 'z'){
            if(k[j] >= 'a' && k[j] <= 'z'){
                s[i] -= k[j]-'a';
            }else{
                s[i] -= k[j] - 'A';
            }
            if(s[i] < 'a'){
                s[i] += 26;
            }
        }else{
            if(k[j] >= 'a' && k[j] <= 'z'){
                s[i] -= k[j]-'a';
            }else{
                s[i] -= k[j] - 'A';
            }
            if(s[i] < 'A'){
                s[i] += 26;
            }
        }
        i++;
        j++;
        if(j >= k.length() ){
            j = 0;
        }
    }
    return s;
}