#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;


struct node {
    double size;
    int part;
    bool operator < (struct node b)const{
        if(fabs(this->size - b.size)<1e-2){
            return this->size * part /100 < b.size * part /100;
        }
        return this->size < b.size;
    }
};

struct node no[200005];

double sum[2005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,b;
    int count = 1;
    while(1){
        double time = 0;
        for(int i = 0; i<n ;i++){
            sum[i] = 0;
        }
        priority_queue<struct node> pq;
        cin>>t>>n>>b;
        double res;
        if(t == 0 && n == 0 && b == 0){
            break;
        }
        struct node temp;
        for(int i = 0; i< t ; i++){
            cin>>temp.size>>temp.part;
            pq.push(no[i]);
        }
        int i = 0;
        while(pq.size()>n){
            sum[i] += pq.top().part*pq.top().size;
            pq.pop();
            i++;
            if(i == n){
                i = 0;
            }
        }
        double minnum = INF;
        for(int i = 0; i<n ; i++){
            minnum = min(minnum,sum[i]);
        }
        for(int i = 0; i<n; i++){
            sum[i] -= minnum;
        }
        

        cout<<"Case "<<count<<": "<<res<<endl;
        count++;
    }
    return 0;
}