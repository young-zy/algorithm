#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

string str;
long n,answer=0;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    cin>>str;
    int con = 0;
    while(!con){
        for(int i = 0; i <= str.length()-1 ; i += 2){
            while(str[i] == str[i+1]){
                str.erase(i+1,1);
                answer++;
            }
        }
        if(str.length() & 1){
            answer++;
            str.erase(str.length()-1,1);
        }
        if(str.length()==0){
            con = 1;
            continue;
        }
        if((str.length() % 2) != 0){
            con = 0;
            continue;
        }

        for(int i = 0 ; i <= str.length() - 1 ; i += 2){
            if(str[i+1] == str[i]){
                con = 0;
                continue;
            }
        }
        con = 1;
    }
    cout<<answer<<endl;
    cout<<str;
    return 0;
}