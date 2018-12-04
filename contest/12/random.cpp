#include<bits/stdc++.h>

using namespace std;

int main(){
    char ch[4] = {'L','U','R','D'};
    ofstream out;
    out.open("D:\\algorithm\\contest\\12\\output.txt",ios::app);
    srand((unsigned)time(NULL));
    for(int i = 0; i< 49999;i++){
        int j = rand()%4;
        out<<ch[j];
    }
    out.close();
    return 0;
}