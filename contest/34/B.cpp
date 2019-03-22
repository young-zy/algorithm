#include<bits/stdc++.h>

using namespace std;

int main(){
    long n;
    int m,k;
    scanf("%ld %d %d",&n,&m,&k);
    int a[k];
    long n1 = n;
    for(int i =0 ;i < k; i++){
        int temp;
        scanf("%d",&temp);
        //scanf("%d",&a[i]);
        if(n1 >= temp){
            n1-=temp;
            m--;
        }else{
            continue;
        }
        if(m == 0){
            break;
        }
    }
    if(m > 0){
        cout<<-1;
        return 0;
    }
    n -= n1;
    cout<<n;
    return 0;
}