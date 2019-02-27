#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    set<string> se;
    priority_queue<string, vector<string>, greater<string> > pq;
    for(size_t i = 0; i < n; i++)
    {
        string temp;
        cin>>temp;
        se.insert(temp);
    }
    for(set<string>::iterator it = se.begin(); it != se.end(); it++){
        pq.push(*it);
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}