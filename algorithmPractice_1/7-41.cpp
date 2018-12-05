#include<bits/stdc++.h>

using namespace std;

int main(){
    set<string> s;
    int in;
    scanf("%d",&in);
    for(int i = 0; i < in;i++){
        string temp;
        cin>>temp;
        s.insert(temp);
    }
    cout<<"Min is: " << *s.begin();
    return 0;
}