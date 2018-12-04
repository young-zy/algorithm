#include<bits/stdc++.h>

using namespace std;

int main(){
    int input;

    scanf("%d",&input);
    int a[input];
    for(int i = 0; i<input; i++){
        a[i] = i+1;
        printf("%d",a[i]);
    }
    printf("\n");
    while(next_permutation(a,a+input)){
        for(int i = 0; i<input; i++){
            printf("%d",a[i]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}