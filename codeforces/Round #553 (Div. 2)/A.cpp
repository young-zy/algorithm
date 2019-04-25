#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string a;
    string b = "ACTG";
    cin>>a;
    int minsum = 99999;
    for(int i = 0; i<= n-4;i++){
        int sum = 0;
        for(int j = 0; j < 4 ; j++){
            int e = fabs(b[j]-a[i+j]);
            int f = min(b[j],a[i+j])-'A'+'Z'-max(b[j],a[i+j])+1;
            sum += min(e,f);
        }
        minsum = min(minsum,sum);
    }
    cout<<minsum;
    return 0;
}