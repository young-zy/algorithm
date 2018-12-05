#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        string a;
        cin>>a;
        int num;
        scanf("%d",&num);
        int temp = num;
        int j = 0;
        int k = 1;
        while(1){
            if(a[j] == 'a'){
                j++;
                continue;
            }
            if(a[k] == 'a'){
                k++;
                continue;
            }
            if(k == j){
                k++;
            }
            if(a[j]>a[k]){
                a[j] = 'a';
                temp--;
                j = 0;
                k = 1;
            }
            j++;
            k++;
            if(temp == 0){
                break;
            }
        }
        j = 0;
        while(1){
            if(a[j] == '\0'){
                break;
            }else if(a[j] == 'a'){
                j++;
                continue;
            }
            printf("%c",a[j]);
            j++;
        }
    }
    return 0;
}