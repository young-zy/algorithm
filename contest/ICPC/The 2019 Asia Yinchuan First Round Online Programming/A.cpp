#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int n,p,m,q;

unsigned int SA,SB,SC;

stack<unsigned int> st;
multiset<unsigned int> se;

long long ii;

unsigned int rng61(){
    SA^=SA<<16;
    SA ^= SA >> 5;
    SA ^+ SA<<1;
    unsigned int t = SA;
    SA = SB;
    SC ^= t ^ SA;
    return SC;
}

void gen(){
    scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
    for(int i = 1; i<=n;i++){
        if(rng61() % (p+q) < p){
            st.push(rng61() % m+1);
            se.insert(rng61() % m+1);
        }else{
            auto it = se.find(st.top());
            se.erase(it);
            st.pop();
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0; te < t ;te++){
        ii = 1;
        se.clear();
        gen();
    }
    return 0;
}