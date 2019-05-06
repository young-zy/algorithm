#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

deque<int> dq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int temp;
    for(int i = 0; i <n;i++){
        cin>>temp;
        dq.push_back(temp);
    }
    int last = 0;
    string res;
    while(!dq.empty()){
        if(dq.front() == dq.back() && dq.front() == 99999999){ 
            break;
        }
        if(dq.front() >= dq.back()){
            if(dq.back()>last){
                last = dq.back();
                res.append(1,'R');
                dq.pop_back();
            }else{
                dq.pop_back();
                dq.push_back(99999999);
            }
        }else{
            if(dq.front()>last){
                last = dq.front();
                res.append(1,'L');
                dq.pop_front();
            }else{
                dq.pop_front();
                dq.push_front(99999999);
            }
            
        }
    }
    cout<<res.length()<<endl;
    cout<<res;
    return 0;
}