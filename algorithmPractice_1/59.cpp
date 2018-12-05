#include<bits/stdc++.h>

using namespace std;

int main(){
    int input;
    scanf("%d",&input);
    char ch[1001];
    memset(ch,' ',sizeof(ch));
    fflush(stdin);
    cin.getline(ch,1001);
    int i =0;
    while(ch[i] != '\0'){
        i++;
    }
    ch[i] = ' ';
    int num = i % input;
    int step = input;
    int j = i-num;
    if(num == 0){
        j -= step;
    }
    for(int k = 0;k < input;k++){
        for(int h = 0;h < i;h+=step){
            printf("%c",ch[j - h +k]);
        }
        if(k != input-1){
            printf("\n");
        }
    }
    return 0;
}