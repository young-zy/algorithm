#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    int t;
    cin>>t;
    int n;
    long long sum = 0;
    map<int ,int> ma;
    for(int te= 0; te < t; te++){
        sum = 0;
        cin>>n;
        int temp;
        int maxnum = -INF;
        for(int i = 0; i<n-1 ; i++){
            cin>>temp;
            sum += temp;
            maxnum = max(maxnum,temp);
            ma[temp]++;
        }
        int x = 0;
        double maxprob = 0;
        int num = 0;
        while(num > (3*n-2*sum)/(2-3*n)){
            int test = (sum+num)*2.0/n/3;
            if(test == num ){
                double prob = 1.0/(ma[num]+1);
                if(maxprob <= prob){
                    x = num;
                    maxprob = prob;
                }
            }
            num++;
        }
        printf("%d %.2lf\n",x,maxprob);
    }
    return 0;
}