#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int a[1000005];
int b[10005];
int ne[10005];

int main(){
    int t;
    cin>>t;
    for(int ti = 0; ti < t; ti++){
        int n,m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i<n ; i++){
            scanf("%d",&a[i]);
        }
        long long val = 0;
        for(int i = 0; i<m ; i++){
            scanf("%d",&b[i]);
            val += b[i];
        }
        long long res = 0;
        for(int i = 0; i<m ; i++){
            res += a[i];
        }
        int i = 0;
        int flag = 0;
        while( i+m <= n ){
            if(res == val){
                int j = 0;
                for(; j<m ; j++){
                    if(a[i+j] != b[j]){
                        break;
                    }
                }
                if(j == m && a[i+m-1] == b[m-1]){
                    flag = 1;
                    printf("%d\n",i+1);
                }
            }
            if(flag == 1){
                break;
            }
            res -= a[i];
            res += a[i+m];
            i++;
        }
        if(flag == 0){
            printf("-1\n");
        }
    }
    return 0;
}

// void gen(){
//     ne[0] = 0;
//     int i = 1;
//     int len = 0;
//     while(i < m){
//         if(b[i] == b[len]){
//             len++;
//             ne[i] = len;
//             i++;
//         }else{
//             if(len > 0){
//                 len = ne[len-1];
//             }else{
//                 ne[i] = len;
//                 i++;
//             }
//         }
//     }
// }