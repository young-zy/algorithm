#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,u,d;
    int time;
    while(scanf("%d %d %d",&n,&u,&d)){
        if(n == 0 && d == 0 && u == 0){
            break;
        }
        int time = 0;
        int height = 0;
        while(height<n){
            height += u;
            time ++;
            if(height >= n){
                break;
            }
            height -= d;
            time ++;
        }
        printf("%d\n",time);
    }
    return 0;
}