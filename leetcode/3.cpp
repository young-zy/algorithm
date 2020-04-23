#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> ma;
        int start = 0;
        int maxlength = 0;
        for(int i =0 ; i<s.length();i++){
            if(!ma[s[i]]){
                ma[s[i]] = i+1;
            }else{
                if(start < ma[s[i]])
                    start = ma[s[i]];
                ma[s[i]] = i+1;
            }
            int length = i-start+1;
            printf("%d\n",length);
            maxlength = max(maxlength,length);
        }
        return maxlength;
    }
};