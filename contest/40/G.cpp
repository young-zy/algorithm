#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0; i< t ; i++){
        int a,b;
        char ch;
        scanf("%o%c%o",&a,&ch,&b);
        if(ch == '+'){
            printf("%x\n",a+b);
        }else{
            printf("%x\n",a-b);
        }
    }
    return 0;
}