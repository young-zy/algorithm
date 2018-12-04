#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    scanf("%d",&num);
    for(int i = 0; i< num;i++){
        char ch[51];
        scanf("%s",ch);
        for(int j = 0; ch[j]!= '\0';j++){
            if(ch[j] == 'a' || ch[j] == 'e' ||ch[j] == 'i' || ch[j] == 'o' ||ch[j] == 'u'
            ||  ch[j] == 'A' || ch[j] == 'E' ||ch[j] == 'I' || ch[j] == 'O' ||ch[j] == 'U'){
                ch[j] = toupper(ch[j]);
            }else{
                ch[j] = tolower(ch[j]);
            }
        }
        printf("%s\n",ch);
    }
    return 0;
}