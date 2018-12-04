#include <bits/stdc++.h>

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int n;
    string m;
    cin>>n>>m;
    int flag = 1;
    for(int i = 0;i<m.length();i++){
        if(m[i] != m[m.length()-i-1]){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        cout<<"STEP=0";
        return 0;
    }
    flag = 0;
    for(int i = 0; i<30;i++){
        string temp = "";
        if(n == 16){
            char ch[] = {'A','B','C','D','E','F'};
            int flag = 0;
            for(int j = m.length()-1;j>=0 || flag == 1;j--){
                int res = 0;
                if(flag == 1){
                    res += 1;
                    flag = 0;
                }
                if(j != -1){
                    int a;
                    int b;
                    if(m[j]>57){
                        a = m[j]-65 + 10;
                    }else{
                        a = m[j]-48;
                    }
                    if(m[m.length()-j-1]>57){
                        b = m[m.length()-j-1]-65 + 10;
                    }else{
                        b = m[m.length()-j-1]-48;
                    }
                    
                    res += a+b;
                    if(res >= n){
                        res -= n;
                        flag = 1;
                    }
                }
                if(res >= 10){
                    temp.insert(0,1,(res+55));
                }else{
                    temp.insert(0,1,(res+48));
                }
                //cout<<temp<<endl;
            }
        }else{
            int flag = 0;
            for(int j = m.length()-1;j>=0 || flag == 1;j--){
                int res = 0;
                if(flag == 1){
                    res += 1;
                    flag = 0;
                }
                if(j != -1){
                    res += (m[j]-48)+(m[m.length()-j-1]-48);
                    if(res >= n){
                        res -= n;
                        flag = 1;
                    }	
                }
                temp.insert(0,1,(res+48));
                //cout<<temp<<endl;
            }
        }
        m = temp;
        //cout<<m<<endl;
        flag = 1;
        for(int i = 0;i<m.length();i++){
            if(m[i] != m[m.length()-i-1]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            cout<<"STEP="<<i+1;
            return 0;
        }
    }
    printf("Impossible!");
    return 0;
}