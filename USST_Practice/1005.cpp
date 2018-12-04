#include<bits/stdc++.h>

using namespace std;

char a[20][20];

int counts = 0;
int w,h;

void dfs(int i, int j){
    if(a[i][j] != '.' && a[i][j] != '@'){
        return;
    }
    counts++;
    a[i][j] = '!';
    if(i>0){
        dfs(i-1,j);
    }
    if(i<h-1){
        dfs(i+1,j);
    }
    if(j>0){
        dfs(i,j-1);
    }
    if(j<w-1){
        dfs(i,j+1);
    }
}

int main(){
    while(1){
        int starti,startj;
        cin>>w>>h;
        if(w == 0 || h == 0){
            break;
        }
        for(int i = 0; i< h;i++){
            getchar();
            for(int j = 0; j< w;j++){
                scanf("%c",&a[i][j]);
                if(a[i][j] == '@'){
                    starti = i;
                    startj = j;
                }
            }
        }
        dfs(starti,startj);
        printf("%d\n",counts);
        counts = 0;
    }
    return 0;
}