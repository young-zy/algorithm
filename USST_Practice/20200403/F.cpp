#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    int l1 = s1.length();
    int l2 = s2.length();
    s1.append(s1);
    s2.append(s2);
    int res = -INF;
    for(int i = 0; i<l1 ; i++){
        for(int j = 0; j< l2; j++){
            int l = 0;
            int k = i;
            int m = j;
            while(s1[k] == s2[m] && l < min(l1,l2)){
                l++;
                k++;
                m++;
            }
            res = max(res,l);
        }
    }
    cout<<res;
    return 0;
}