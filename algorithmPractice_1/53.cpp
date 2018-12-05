#include<bits/stdc++.h>

using namespace std;

int main(){
    char ch[51];
    int evenflag = 0;
    int _0 = 0;
    scanf("%s",ch);
    int i = 0;
    int _2 = 0;
    while(ch[i]!='\0'){
        
        if(ch[i] == '-'){
            _0 = 1;
        }
        if(ch[i] == '2'){
            _2++;
        }
        i++;
    }    
    if((ch[i-1] - 48) % 2 == 0){
        evenflag = 1;
    }
    float ans;
    if(_0 == 1){
        i--;
    }
    ans = (float)_2/i;
    if(_0 == 1){
        ans *= 1.5;
    }
    if(evenflag == 1){
        ans *= 2;
    }
    ans *= 100;
    printf("%.2f%%",ans);

    return 0;
}