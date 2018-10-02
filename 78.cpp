#include<bits/stdc++.h>

using namespace std;

int main(){ 
    int flag[8];
    char ch[101];
    int i =0;
    while(1){
        ch[i] = getchar();
        if(i != 0 && ch[i-1] == '.' && ch[i]=='\n'){
            break;
        }
        i++;
    }
    i-=2;
    for(int j = 0;j<i;j++){
        if(ch[j] == '/' && ch[j+1] == '*'){
            flag[0]++;
            j++;
            continue;
        }
        if(ch[j] == '*' && ch[j+1] == '/'){
            flag[1]++;
            j++;
            continue;
        }
    }
    printf("%s",ch);
    return 0;
}