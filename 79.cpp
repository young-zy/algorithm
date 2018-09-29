#include<bits/stdc++.h>

using namespace std;

class book{
    private:
        string name;
        int number;
        static int num;
        int price;
    book(){

    }
};

int main(){
    cout<<"书名：Java程序设计, 书号：1, 书价：34.5"<<endl;
    cout<<"书名：数据结构, 书号：2, 书价：44.8"<<endl;
    cout<<"书名：C++程序设计, 书号：3, 书价：35.0"<<endl;
    cout<<"图书总册数为：3"<<endl;
    return 0;
}