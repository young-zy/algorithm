#include<bits/stdc++.h>

using namespace std;

int n,k,s;

int a[101] =  { 0 } ;
int b[101];

int max_square = 0;
int max_s[100] = {0};

void dfs(int used,int sum,int index,int square){
    if(used == k){
        if(sum == s){
            if(square > max_square){
                max_square = square;
                for(int i = 0; i< n;i++){
                    max_s[i] = b[i];
                }
                return;
            }
        }else{
            return;
        }
    }
   if(sum + a[index] <= s && index <= n){
        b[index] = 1;
        dfs(used + 1,sum +a[index],index +1,square + (int)pow(a[index],2));
        b[index] = 0;
        dfs(used, sum, index + 1, square);
    }else{
        return;
    }
    return;
}

int main(){
    scanf("%d %d %d",&n,&k,&s);
    for(int i = 0; i< n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    dfs(0,0,0,0);
    printf("%d\n",max_square);
    int c = 0;
    for(int i = 0;i<n;i++){
        if(max_s[i] == 1){
            if(c != 0){
                printf(" ");
            }
            c++;
            printf("%d",a[i]);
        }
    }
    return 0;
}