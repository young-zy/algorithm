#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>

using namespace std;

int a[1000006];

int main(){
    int n;
    int temp;
    int res;
    map<int, int> ma;
    while(~scanf("%d",&n)){
        memset(a,0,sizeof(a));
        for(int i = 0; i<n ; i++){
            scanf("%d",&temp);
            a[temp]++;
            if(a[temp] == 2){
                res = temp;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}