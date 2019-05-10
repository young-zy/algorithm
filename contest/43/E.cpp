#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define Maxn 100000

using namespace std;

bool _match(char a, char b);
int patmatch(int ls,const char* str ,int lp,const char *pat);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string w;
    string w1;
    int t;
    cin>>w;
    for(int i = w.length()-1;i >=0;i--){
        w1.append(1,w[i]);
    }
    cin>>t;
    for(int i = 0 ; i< t ; i++){
        string s;
        cin>>s;
        if(patmatch(s.length(),s.c_str(),w.length(),w.c_str()) == -1 && patmatch(s.length(),s.c_str(),w1.length(),w1.c_str()) == -1){
            cout<<"NO";
        }else{
            cout<<"YES";
        }
        cout<<endl;
    }
    return 0;
}

int patmatch(int ls,const char* str ,int lp,const char *pat){
    int fail[Maxn] = {-1};
    int i = 0, j;
    for(j = 1; j<lp;j++){
        for(i = fail[j-1]; i>=0 && _match(pat[i+1],pat[j]);i = fail[i]);
        if(_match(pat[i+1],pat[j])){
            fail[j] = i+1;
        }else{
            fail[j] = -1;
        }
    }
    for(i = j = 0; i < ls&&j < lp;i++){
        if(_match(str[i],pat[j])){
            j++;
        }else if(j){
            j = fail[j-1]+1;
            i--;
        }
    }
    return j == lp ? (i-lp):-1;
}

bool _match(char a, char b){
    if(a == b){
        return true;
    }else if(a == '?' || b == '?'){
        return true;
    }else{
        return false;
    }
}