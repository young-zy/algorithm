#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0; i<t;i++){
        int n;
        string type;
        string name;
        scanf("%d",&n);
        int length = 0;
        for(int j = 0;j<n;j++){
            cin>>type>>name;
            getchar();
            if(type == "int"){
                length += 4;
            }else if(type == "bool"){
                length += 1;
            }else if(type == "long"){
                length += 8;
            }else if(type == "double"){
                length += 8;
            }else if(type == "float"){
                length += 4;
            }else if(type == "char"){
                length += 1;
            }
        }
        if(length % 1024 != 0){
            length = length / 1024 +1;
        }
        cout<<length<<endl;
    }

    return 0;
}