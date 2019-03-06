#include <bits/stdc++.h>

using namespace std;

int main()
{
    long l,n;
    scanf("%ld %ld",&l,&n);
    long sum = 0;
    for(int i =0 ;i<l;i++){
        long temp = 1;
        for(int j = i;j>0;j--){
            temp *= 26;
        }
        sum += 25*temp;
    }
    int a[l];
    long i = l-1;
    n = sum - n + 1;
    while(1){
        if(n == 1 || i == -1){
            break;
        }
        a[i] = n%26;
        n/=26;
        i--;
    }
    for(long i =0;i<l;i++){
        printf("%c",a[i]+'a');
    }


    return 0;
}