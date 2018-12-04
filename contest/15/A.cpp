#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long a[200006];

int main() {
    long long n;
    long long k;
    scanf("%lld %lld",&n,&k);
    for(long long i =0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    long long answer;
    if(k == 0){
        if(a[0] == 1){
            answer = -1;
        }else{
            answer = a[0]-1;
        }
    }else{
        answer=a[k-1];
    }
    if(answer>1000000000){
        answer=-1;
    }
    if(a[k] == answer && n !=k){
        answer=-1;
    }
    if(answer <= 0){
        answer = -1;
    }
    printf("%lld",answer);
    return 0;
}
