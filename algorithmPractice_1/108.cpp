#include<bits/stdc++.h>

using namespace std;

int main(){
    char a[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    char ch;
    int count = 0;
    string in;
    cin>>in;
    int i = 0;
    while(1){
        if(in[i] == '-'){
            printf("fu");
            count++;
        }else if(in[i] == '\0'){
            break;
        }else{
            if(count != 0){
                printf(" ");
            }
            printf("%s",a[in[i]-48]);
            count++;
        }
        i++;
    }
    system("pause");
    return 0;
}