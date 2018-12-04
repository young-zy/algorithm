#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string str[n];
    for(int i = 0; i<n ;i++){
        cin>>str[i];
    }
    long count = 0;
    int a[n][2];
    memset(a,0,sizeof(a));
    for(int i = 0; i< n;i++){
        for(int j = 0; j<str[j].length();j++){
            if(str[i][j] == '('){
                a[i][0]++;
            }else{
                a[i][1]++;
            }
        }
    }
    for(int i = 0; i<n;i++){
        for(int j = i;j<n;j++){
            if(a[i][0] +a[j][0] != a[i][1] + a[j][1]){
                continue;
            }
            stack<int> s;
            string temp = str[i] +str[j];
            for(int k = 0; k < temp.length();k++){
                if(temp[k] == '('){
                    s.push(1);
                }else{
                    if(s.empty()){
                        break;
                    }else{
                        s.pop();
                    }
                    if(k == temp.length()-1 && s.empty()){
                        count++;
                    }
                }
            }
            s.empty();
            temp = str[j] +str[i];
            for(int k = 0; k < temp.length();k++){
                if(temp[k] == '('){
                    s.push(1);
                }else{
                    if(s.empty()){
                        break;
                    }else{
                        s.pop();
                    }
                    if(k == temp.length()-1 && s.empty()){
                        count++;
                    }
                }
            }
        }
    }
    count<<count;
    return 0;
}