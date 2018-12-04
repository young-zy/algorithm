#include<bits/stdc++.h>

using namespace std;

int main(){
    int N,K;
    scanf("%d %d",&N,&K);
    int a[N];
    for(int i = 0; i<N;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<N-1 &&i < K;i++){
        for(int j = 0; j <N-1;j++){
            if(a[j]> a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i = 0;i<N;i++){
        if(i != 0){
            printf(" ");
        }
        printf("%d",a[i]);
    }
    system("pause");
    return 0;
}