#include<bits/stdc++.h>

using namespace std;

int main(){
    char ch;
    int res = 0;
    // while(~scanf("%c",&ch)){
    //     res += ch;
    // }
    srand(time(NULL));
    if(rand() % 2 != 0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}