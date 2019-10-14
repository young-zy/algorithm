#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

char ch[100005];

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    //clock_t t1 = clock();
    int n,k;
    scanf("%d %d",&n,&k);
    string s;
    cin>>s;
    //scanf("%s",ch);
    //s.append(ch);
    int flag = 0;
    unsigned long long temp1 = -1;
    unsigned long long temp2 = -1;
    while(1){
        temp1 = s.find("447",temp1+1);
        if(temp1 == string::npos){
            flag++;
            break;
        }else if(temp1 %2 == 0){
            break;
        }else{
            continue;
        }
    }
    while(1){
        temp2 = s.find("477",temp2+1);
        if(temp2 == string::npos){
            flag++;
            break;
        }else if(temp2 % 2 == 0){
            break;
        }else{
            continue;
        }
    }
    unsigned long long x = 0;
    while(k){
        x = s.find("47",x);
        if(x == string::npos){
            break;
            flag = 2;
        }
        if(x >= temp1 || x>=temp2){
            break;
        }
        if(x % 2){
            s[x] = '7';
        }else{
            s[x+1] = '4';
        }
        k--;
    }
    if(flag != 2 && k>0){
        if(temp1 < temp2){
            k %=2;
            if(k){
                s[temp1+1] = '7';
            }
        }else{
            k %=2;
            if(k){
                s[temp2+1] = '4';
            }
        }
    }
    clock_t t2 = clock();
    cout<<s;
    //strcpy(ch,s.c_str());
    //printf("%s",s.c_str());
    //cout <<endl<< (t2 - t1) * 1.0 / CLOCKS_PER_SEC * 1000 << endl;
    //cout <<endl<< (clock() - t1) * 1.0 / CLOCKS_PER_SEC * 1000 << endl;
    return 0;
}