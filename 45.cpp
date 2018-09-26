#include<bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    scanf("%d %d",&a,&b);

    int sum = (b+a)*(b-a+1)/2;
    for(int i = a; i<=b;){
        for(int j = 0;j<5 && i<=b;j++){
            printf("%5d",i);
            i++;
        }
        printf("\n");
    }
    printf("Sum = %d",sum);
    return 0;
}