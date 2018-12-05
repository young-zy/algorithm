#include<bits/stdc++.h>

using namespace std;

char cM = 'A' +'B' + 'C';

void han(int i , char c,char c2){
    if(i == 1){
        printf("1 from %c to %c",c,c2);
    }else{
        han(i - 1, c, cM-c-c2);
        printf("%d from %c to %c",i,c,c2);
        han(i - 1, cM-c-c2,c2);
    }
}

int main(){
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    han(n,'A','C');
    return 0;
}