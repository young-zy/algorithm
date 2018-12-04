#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    string a;
    cin>>a;
    string b;
    map<char,int> m;
    string c;
    for(int i = a.length()-1; i>=0;i--){
        if(m[a[i]] == 0){
            c.append(string(1,a[i]));
        }
        m[a[i]]++;
    }
    for(map<char,int>::iterator it = m.begin();it!=m.end();it++){
        if(it->second > a.length()/2){
            printf("impossible");
            return 0;
        }
    }
    
    for(int i = 0; i< a.length();i++){
        int j;
        int flag = 0;
        for(j = 0;j<c.length();j++){
            if(m[c[j]] == 0){
                continue;
            }
            if(c[j] != a[i]){
                b.append(string(1,c[j]));
                m[c[j]]--;
                if(m[c[j]] == 0){
                    c.erase(j,1);
                    flag = 1;
                }
                break;
            }
        }
        
        if(j == c.length() && j!= 0 && flag == 0){
            for(j = 0;j<b.length();j++){
                if(c[0] != a[j] && a[i] != b[j]){
                    char temp = b[j];
                    b.erase(j,1);
                    b.insert(j,string(1,c[0]));
                    b.append(string(1,temp));
                    break;
                }
            }
        }
    }
    cout<<b;
    return 0;
}