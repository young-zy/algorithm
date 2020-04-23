#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int a[105][105];
int res[105][105];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m; j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j] == '?'){
                a[i][j] = 0;
            }
        }
    }
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j] == '*'){
                if(i > 0){
                    if(j > 0){
                        if(a[i-1][j-1] != '*'){
                            res[i-1][j-1]++;
                        }
                    }
                    if(j < m-1){
                        if(a[i-1][j+1] != '*'){
                            res[i-1][j+1]++;
                        }
                    }
                    if(a[i-1][j] != '*'){
                        res[i-1][j]++;
                    }
                }
                if( i < n-1 ){
                    if(j > 0){
                        if(a[i+1][j-1] != '*'){
                            res[i+1][j-1]++;
                        }
                    }
                    if(j < m-1){
                        if(a[i+1][j+1] != '*'){
                            res[i+1][j+1]++;
                        }
                    }
                    if(a[i+1][j] != '*'){
                        res[i+1][j]++;
                    }
                }
                if(j > 0){
                    if(a[i][j-1] != '*'){
                        res[i][j-1]++;
                    }
                }
                if(j < m-1){
                    if(a[i][j+1] != '*'){
                        res[i][j+1]++;
                    }
                }
            }
        }
    }
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m;j++){
            if(a[i][j] == '*'){
                printf("*");
            }else{
                printf("%d",res[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}