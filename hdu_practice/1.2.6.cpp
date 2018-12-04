#include<bits/stdc++.h>

using namespace std;
int main(){
    int num;
    scanf("%d",&num);
    for(int i = 0;i < num; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a == b || b == c || a == c){
            printf("perfect\n");
        }else if((int)pow(a,2) == (int)pow(b,2) + (int)pow(c,2)
        ||  (int)pow(b,2) == (int)pow(a,2) + (int)pow(c,2)
        ||  (int)pow(c,2) == (int)pow(b,2) + (int)pow(a,2)
        ){
            printf("good\n");
        }else{
            printf("just a triangle\n");
        }
    }
    return 0;
}