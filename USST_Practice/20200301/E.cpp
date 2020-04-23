#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int a[100005][2];

int findroot(int c){
    if(a[c][0] == -1){
        return c;
    }else{
        return a[c][0] = findroot(a[c][0]);
    }
}

int merge(int b, int c){
    c = findroot(c);
    b = findroot(b);
    if(c == b){
        return a[b][1];
    }else{
        if(b<c){
            swap(b,c);
        }
        a[b][0] = c;
        a[c][1] = a[b][1]+a[c][1];
        return a[c][1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        memset(a,-1,sizeof(a));
        int f;
        cin>>f;
        for(int i = 0; i<=100000 ; i++){
            a[i][1] = 1;
        }
        map<string, int> ma;
        string s1,s2;
        int cnt = 1;
        for(int i = 0; i<f ; i++){
            cin>>s1>>s2;
            if(ma[s1] == 0){
                ma[s1] = cnt++;
            }
            if(ma[s2] == 0){
                ma[s2] = cnt++;
            }
            cout<<merge(ma[s1], ma[s2])<<endl;
        }
    }
    return 0;
}