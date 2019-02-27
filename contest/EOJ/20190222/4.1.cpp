#include<bits/stdc++.h>

using namespace std;

unsigned long long pow(unsigned long long a, int b);
//int judge(unsigned long long j,int m,int k);


int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0; i<t;i++){
        unsigned long long l,r;
        unsigned long long count = 0;
        scanf("%llu %llu",&l,&r);
        int k,m;
        scanf("%d %d",&k,&m);
        unsigned long long num = pow(k,m);
        unsigned long long j = 1;
        unsigned long long t = m;
        while(t){
            t--;
            r/=k;
        }
        
        while(1){
            if(j % k == 0){
                j++;
                continue;
            }
            unsigned long long num2 = num*j;
            if(num2 <= r && num2 >=l){
                count++;
            }
            if(num2>=r){
                break;
            }
            j++;
        }
        printf("%llu\n",count);
    }
    return 0;
}

unsigned long long pow(unsigned long long a, int b){
    unsigned long long res  = 1;
    for(int i =0 ;i<b;i++){
        res*=a;
    }
    return res;
}

// int judge(unsigned long long j,int m,int k){
//     int flag = 1;
//     unsigned long long num = j;
//     for(int i1 = 0; i1<=m; i1++){
//         if(num % k !=0){
//             if(i1==m){

//             }else{
//                 flag = 0;
//                 break;
//             }
//         }else{
//             if(i1 == m){
//                 flag = 0;
//                 break;
//             }
//             num/=k;
//             if(num == 0 && i1 <m -1){
//                 flag = 0;
//                 break;
//             }
//         }
//     }
//     return flag;
// }