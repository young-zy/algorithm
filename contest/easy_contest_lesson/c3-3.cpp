#include<bits/stdc++.h>

using namespace std;

int main(){
    double a[300];
    a[0] = (double)1/2;
    for(int i = 1; i< 300 ;i++){
        a[i] = a[i-1] + (double)1/(i+2);
    }
    double in;
    cin>>in;
    while(fabs(in - 0.00) >= 1e-3){
        for(int res = 0;res < 300;res++){
            if(a[res] > in){
                cout<<res+1<<" card(s)"<<endl;
                break;
            }
        }
        cin>>in;
    }
    return 0;
}