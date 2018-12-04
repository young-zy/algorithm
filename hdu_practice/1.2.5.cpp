#include<bits/stdc++.h>

using namespace std;

int main(){
    char input[256];
    cin.getline(input,256);
    while(input[0] != '#'){
        int sum = 0;
        for(int i = 0;input[i] != '\0';i++){
            if(input[i] == ' '){
                continue;
            }else{
                sum += (input[i] - 65 + 1) * (i + 1);
            } 
        }
        cout<<sum<<endl;
        cin.getline(input,256);
    }
    return 0;
}