#include<bits/stdc++.h>

using namespace std;

int main(){
    for(int i = 2991;i<=9999;i++){
        int temp = i;
        int count = 0;
        int a[4],b[4],c[4];
        int suma = 0;
        int sumb = 0;
        int sumc = 0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int j = 0; j<4;j++){
            b[j] = temp % 16;
            temp /=16;
        }
        temp = i;
        for(int j = 0; j < 4;j++){
            a[j] = temp % 10;
            temp /= 10;
        }
        temp = i;
        for(int j = 0; j < 4;j++){
            c[j] = temp % 12;
            temp /= 12;
        }
        for(int j = 0; j < 4;j++){
            suma += a[j];
            sumb += b[j];
            sumc += c[j];
        }
        if(suma == sumb && sumb == sumc){
            printf("%d\n",i);
        }
    }
    return 0;
}