#include<bits/stdc++.h>

using namespace std;

//问题在于0k000000


int main(){
    string a;
    cin>>a;
    int count = 0;
    for(int i = 0;a[i+1]!= 0 ;){
        if(a[i] == '0' && a[i+1] == 'k'){
            int j =2;
            int flag = 0;
            
            while(1){
                int flag2 = 0;
                if(a[i+j]>='0' && a[i+j]<='9' || a[i+j]>='A' && a[i+j]<='E'){
                    flag = 1;
                    if(j == 2){
                        if(count != 0){
                            printf("\n");
                        }
                        printf("0k");
                        count++;
                    }
                    if(a[i+j] != '0'){
                        flag2 = 1;
                    }
                    printf("%c",a[i+j]);
                    j++;
                }else if(a[i+j] == '\'' && flag == 1){
                    flag = 0;
                    i = i+j;
                    break;
                }else{
                    if(flag == 1){
                        flag = 0;
                        i = i+j;
                        break;
                    }else{
                        break;
                    }
                }
            }
        }
        i++;
    }
    return 0;
}