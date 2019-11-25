#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        return manacher(s);
    }
    
    string manacher(string s) {
        // 插入 '#'
        //字符串开始为$
        string t = "$#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += "#";
        }
        vector<int> p(t.size(), 0);
        int mx = 0; // 回文串最右侧位置
        int id = 0; // 回文串中心位置
        int resLen = 0;     // 结果串的长度 
        int resCenter = 0;  // 结果串的中心
        for (int i = 1; i < t.size(); i++) {
            if ( mx > i ){                                  // 当 下标未越过 回文右界时 
                p[i] = min(p[ 2 * id - i ], mx - i );       // 取 与自己关于id对称的回文长度 和 自己到回文串末尾 的最小值 
            }else{                                          // 否则设为1
                p[i] = 1;
            }
            while (t[i + p[i]] == t[i - p[i]]){             // 扩展计算是否有更多回文
                ++p[i];
            }
            // 更新回文串最右侧位置和中心位置
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            // 更新答案
            if (resLen < p[i]) {
                resLen = p[i];
                resCenter = i;
            }
        }
        //结果的左界是 （中心-长度）/2，右界是长度-1
        return s.substr((resCenter - resLen) / 2, resLen - 1);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    cout<<Manacher(s);
    return 0;
}