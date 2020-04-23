#include<set>
#include<algorithm>
#include<iostream>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int c[10005];       
int height[10005];

set< pair<int, int> > se;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n,l,h,r;
    cin>>n>>l>>h>>r;
    height[l] = h;
    for(int i = 0; i < r; i++){
        int a,b;
        cin>>a>>b;
        if(a>b){
            swap(a,b);
        }
        if( se.find(make_pair(a,b) ) != se.end() ){
            continue;
        }
        c[a+1]--;
        c[b]++;
        se.insert(make_pair(a,b));
    }
    for(int i = 1; i<=n ; i++){
        height[i] = c[i] + height[i-1];
        cout<< h+height[i] <<endl;
    }
    return 0;
}