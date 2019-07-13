#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0] == a[1] && a[1] == a[2]){
        printf("0");
    }else if(a[0][1] == a[1][1] && a[1][1] == a[2][1]){
        if(a[1][0] - a[0][0] == 1 && a[2][0] - a[1][0] == 1){
            printf("0");
        }else if(a[1][0] - a[0][0] == 1 || a[2][0] - a[1][0] == 1 || a[1][0] - a[0][0] == 2 || a[2][0] - a[1][0] == 2){
            printf("1");
        }else{
            printf("2");
        }
    }else if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2]){
        printf("1");
    }else if(a[1][0] - a[0][0] == 1 && a[1][1] == a[0][1] || a[2][0] - a[1][0] == 1 && a[2][1] == a[1][1] || a[2][0] - a[0][0] == 1 && a[2][1] == a[0][1]){
        printf("1");
    }else if(a[1][0] - a[0][0] == 2 && a[1][1] == a[0][1] || a[2][0] - a[1][0] == 2 && a[2][1] == a[1][1] || a[2][0] - a[0][0] == 2 && a[2][1] == a[0][1]){
        printf("1");
    }else{
        printf("2");
    }
    return 0;
}