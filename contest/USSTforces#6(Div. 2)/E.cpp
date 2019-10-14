#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int ans[11];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int b1,d;
    cin>>b1>>d;
    int count = 1;
    int a = 0;
    int b = 0;
    int c = 0;
    long long odd = 0;
    long long even = 0;
    long long sum = 0;
    int newd = d;
    while(d){
        int temp = d%b1;
        if(count == 1){
            a += temp;
            b += temp;
            c+=temp;
        }
        if(count == 2){
            b += temp*10;
            c+=temp*10;
        }
        if(count == 3){
            c+=temp*100;
        }
        if(count % 2){
            odd += temp;
        }else{
            even += temp;
        }
        sum += temp;
        count++;
        d/=b1;
    }
    int _count = 0;
    if(!(a%2)&&++_count ||!(b%4)&&_count++||a==5 ||!(c%8)&&_count++ ){
        if(a==5){
            _count=1;
        }
        cout<<"2-type"<<endl;
        cout<<_count;                                                                
    }else if(!(sum%3)){
        cout<<"3-type";
    }else if(!((long long)fabs(odd-even)%11)){
        cout<<"11-type";
    }else if((!(a%2))&&(!sum%3)){
        cout<<"6-type";
    }else{
        cout<<"7-type";
    }


    return 0;
}