#include<bits/stdc++.h>

using namespace std;

int a[1000005];
deque<int> dq;
deque<long> dq1;


int main(){
    long n,k;
    cin>>n>>k;
    for(long i = 0; i < n;i ++){
        scanf("%d",&a[i]);
    }
    for(long i = 0; i< n;i++){
        if(dq.empty()){
            dq.push_back(a[i]);
            dq1.push_back(i);
        }else{
            while(!dq.empty() && a[i] > dq.back() ){
                dq.pop_back();
                dq1.pop_back();
            }
            dq.push_back(a[i]);
            dq1.push_back(i);
            if(i-k >= dq1.front()){
                dq1.pop_front();
                dq.pop_front();
            }
        }
        if(i >= k-1){
            printf("%d %ld\n",dq.front(),dq1.front()+1);
        }
    }


    return 0;
}