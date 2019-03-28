#include<bits/stdc++.h>

using namespace std;

int main(){
    long n;
    long count = 0;
    cin>>n;
    list<long> a;
    for(long i =0;i<n;i++){
        long temp;
        cin>>temp;
        a.push_back(temp);
    }
    list<long>::reverse_iterator rit = a.rbegin();
    for(list<long>::iterator it =a.begin() ; it != a.end(); ){
        if(*it == *rit){
            it++;
            rit++;
            //continue;
        }else{
            if(*it > *rit){
                long res = *rit + *(rit++);
                *(rit+1) = res;
                a.erase(rit.base());
            }else{
                long res = *it + *(it++);
                *(it) = res;
                a.erase(--it);
            }
            count++;
        }
    }
    cout<<count;
    return 0;
}