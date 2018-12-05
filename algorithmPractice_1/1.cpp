#include<bits/stdc++.h>

using namespace std;

int main(){
    int input;
    scanf("%d",&input);
    for(int i = 0;i<=input;i++){
        printf("pow(3,%d) = %d\n",i,(int)pow(3,i));
    }
    return 0;
}