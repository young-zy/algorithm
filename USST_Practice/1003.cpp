#include<bits/stdc++.h>

using namespace std;

int main(){
    string isbn;
    cin>>isbn;
    string temp = isbn;
    int sum = 0;
    for(int i = 1;i<=9;i++){
        if(temp[i-1] == '-'){
            temp.erase(i-1,1);
            i--;
            continue;
        }
        sum += (temp[i-1] - 48)*i;
    }
    sum %= 11;
    if(sum+48 == temp[temp.length()-1] || temp[temp.length()-1]=='X' && sum == 10){
        printf("Right");
    }else{
        isbn.erase(isbn.length()-1);
        if(sum == 10){
            isbn.append(1,'X');
        }else{
            isbn.append(1,48+sum);
        }
        cout<<isbn;
    }
    return 0;
}