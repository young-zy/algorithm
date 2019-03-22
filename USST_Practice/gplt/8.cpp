#include<bits/stdc++.h>

using namespace std;

int main(){
    int b[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int n;
    cin>>n;
    int count=0;
    map<int,char> ma;
    ma[0] = '1';
    ma[1] = '0';
    ma[2] = 'X';
    ma[3] = '9';
    ma[4] = '8';
    ma[5] = '7';
    ma[6] = '6';
    ma[7] = '5';
    ma[8] = '4';
    ma[9] = '3';
    ma[10] = '2';
    for(int i =0 ; i< n ;i++){
        string a;
        cin>>a;
        int flag = 1;
        for(int i =0 ;i < 17;i++){
            if(a[i] >= '0' && a[i] <= '9'){
                continue;
            }else{
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            int sum = 0;
            for(int i =0 ;i < 17;i++){
                sum += (a[i]-'0') * b[i];
            }
            sum %= 11;
            if(a[17] != ma[sum]){
                flag = 0;
            }
        }
        if(flag == 0){
            cout<<a<<endl;;
        }else{
            count++;
        }
    }
    if(count == n){
        cout<<"All passed";
    }

    return 0;
}