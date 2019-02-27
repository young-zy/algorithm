#include<bits/stdc++.h>

using namespace std;

int result(int a){
    if(a>9){
        int sum = 0;
        while(a!=0){
            sum+=a%10;
            a/=10;
        }
        return sum;
    }else{
        return a;
    }
}

int main(){
    int a[10000],b[10000];
    int n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d",&n);

    for(int i =0;i<n ;i++){
        a[i] = i+result(i);
        b[a[i]]++;
    }

    for(int i =1;i<n;i++){
        if(b[i] == 0){
            printf("%d\n",i);
        }
    }
    return 0;
}