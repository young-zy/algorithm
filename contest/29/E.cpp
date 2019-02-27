#include<bits/stdc++.h>

using namespace std;

int main(){
    long n;
    long long result = 0;
    scanf("%ld",&n);
    list<long long> li;
    for(long i = 0; i<n;i++){
        long long temp;
        scanf("%lld",&temp);
        li.push_back(temp);
    }
    list<long long>::reverse_iterator rend = li.rend();
    for(list<long long>::reverse_iterator rit = li.rbegin();rit!=li.rend();){
        if(*rit<=0){
            result += *rit * (distance(rit,rend));
            li.erase(std::next(rit).base());
        }else{
            rit++;
        }
    }
    while(!li.empty()){
        result += *li.begin();
        li.pop_front();
    }
    printf("%lld",result);
    return 0;
}