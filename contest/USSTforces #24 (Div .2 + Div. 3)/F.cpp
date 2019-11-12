#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t,sx,sy,ex,ey;
    cin>>t>>sx>>sy>>ex>>ey;
    string s;
    cin>>s;
    int a = ex - sx;
    int b = ey - sy;
    int c[4] = {0};
    int ans = -1;
    for(int i =0 ; i<t;i++){
        if(s[i] == 'N'){
            c[0]++;
        }else if(s[i] == 'E'){
            c[1]++;
        }else if(s[i] == 'S'){
            c[2]++;
        }else{
            c[3]++;
        }
        int flag = 0;
        if(a >= 0){
            if(c[1] >= a){
                flag++;
            }
        }else{
            if(c[3] >= -a){
                flag++;
            }
        }
        if(b >= 0){
            if(c[0] >= b){
                flag++;
            }
        }else{
            if(c[2] >=-b){
                flag++;
            }
        }
        if(flag == 2){
            ans = i+1;
            break;
        }
    }
    cout<<ans;
    return 0;
}