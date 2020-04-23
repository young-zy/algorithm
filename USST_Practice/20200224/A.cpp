#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    int r;
    long double w,l;
    int count = 1;
    while(1){
        cin>>r;
        if(r == 0){
            break;
        }
        cin>>w>>l;
        if(4*r*r < l*l + w*w){
            printf("Pizza %d does not fit on the table.\n", count);
        }else{
            printf("Pizza %d fits on the table.\n",count);
        }
        count++;
    }
    
    return 0;
}