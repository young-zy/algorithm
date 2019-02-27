#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int a[n][6];
    long ssum[5];
    memset(ssum,0,sizeof(ssum));
    int count = 0;
    for(int i = 0;i <n ;i++){
        int sum = 0;
        for(int j = 0 ;j <5;j++){
            scanf("%d",&a[i][j]);
            sum += a[i][j];
        }
        if(sum < 5){
            a[i][5] = 0;
        }else{
            a[i][5] = 1;
            for(int j = 0 ;j <5;j++){
                ssum[j] += a[i][j];
            }
            count++;
        }
    }
    sort(ssum,ssum+5);
    if(ssum[0] > count){
        ssum[0] = count;
    }
    printf("%ld",ssum[0]);
    //system("pause");
    return 0;
}