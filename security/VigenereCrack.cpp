#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int index(string s);

string decrypt(string k, string st);

string find_key(string s, int length);

//参考及样例：https://artofproblemsolving.com/community/c1671h1005767_cracking_the_vigenere_cipher_knowing_the_keyword_length

int main(){
    string s;
    cout<<"密文：";
    cin>>s;
    int len = index(s);
    cout<<"密钥长度为："<<len<<endl;
    string key = find_key(s, len);
    string res = decrypt(key, s);
    cout<<"密钥为："<<key<<endl<<"明文为："<<res;
    return 0;
}

int index(string s){
    int length = 1;
    vector<double> index(s.length());
    set<string> group;
    map<char, int> ma;
    double ci,avg;
    while(1){
        index.clear();
        group.clear();
        for(int i = 0; i<s.length();i+=length){
            string temp;
            temp = s.substr(i, length);
            group.insert(temp);
        }

        for(int i =0 ;i < length;i++){
            ci = 0;
            ma.clear();
            for(auto it: group){
                if(it[i]>='A'&&it[i]<='Z'){
                    it[i] += 'a'-'A';
                }
                ma[it[i]]++;
            }
            for(char ch = 'a'; ch <= 'z'; ch++){
                ci += (double)ma[ch]/group.size()*(ma[ch]-1)/(group.size()-1);
            }
            index[i] = ci;
        }
        avg = 0;
        for(int i = 0; i<length; i++){
            avg += index[i];
        }
        avg /= length;
        if(avg >= 0.06){
            break;
        }else{
            length++;
        }
    }
    return length;
}

string find_key(string s, int length){
    string group[length];
    map<char, int> ma;
    string key = string(length,'a');
    double prob[] = {0.082, 0.015, 0.028, 0.043, 0.127, 0.022, 0.02, 0.061, 0.07, 0.002, 0.008, 0.04, 0.024, 0.067, 0.075, 0.019, 0.001, 0.06, 0.063, 0.091, 0.028, 0.01, 0.023, 0.001, 0.02, 0.001};
    for(int i = 0; i< s.length();i++){
        group[i%length].append(1,s[i]);
    }
    for(int i = 0; i<length; i++){
        int offset = 0;
        ma.clear();
        for(auto it:group[i]){
            if(it>='A'&&it<='Z'){
                it += 'a'-'A';
            }
            ma[it]++;
        }
        double q[26];
        for(int j = 0 ; j<26; j++){
            q[j] = (double)ma['a'+j] / group[i].length();   //出现概率
        }
        double maxIndex = 0;
        for(int j = 0; j< 26;j++){
            double index = 0;
            for(int k = 0; k< 26; k++){
                index += prob[k] * q[(j+k)%26];
            }
            // cout<<index<<endl;
            if(index > maxIndex){
                key[i] = 'a'+j;
                maxIndex = index;
            }
        }
        // cout<<endl;
    }
    return key;
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