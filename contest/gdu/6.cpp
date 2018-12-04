#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0;i< t;i++){
        int n;
        scanf("%d",&n);
        if(n<=0){
            printf("Impossble\n");
        }
        printf("%.8lf\n",acos(-1)*pow(n/acos(-1),2)/2);
    }
    return 0;
}