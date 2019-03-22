#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i< n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int result = 1;
        result *= pow(2,a);
        result *= pow(2,b);
        result *= pow(2,c);
        printf("%d\n",result);
    }
    return 0;
}