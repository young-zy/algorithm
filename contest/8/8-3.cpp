#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int x,y;
    double y0;
    int m=n/2;
    int c = 0;
    for(x = 1; x*x <=m;x++){
        y0 = sqrt(n - x*x);
        y = y0;
        if(fabs(y - y0) < 1E-7){
            printf("%d %d\n",x,y);
            c++;
        }
    }
    if(c == 0){
        printf("No Solution");
    }
    return 0;
}