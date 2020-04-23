#include<iostream>
#include<algorithm>
#include<unordered_set>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int count = 0;
    unordered_set<int> se;
    for(int i = 0; i<=a; i++){
        for(int j = 0; j<=b; j++){
            for(int k = 0; k<=c; k++){
                for(int l = 0; l<=d; l++){
                    for(int m = 0; m<=e; m++){
                        for(int n = 0; n<=f; n++){
                            se.insert( i + 2*j + 3*k + 5*l + 10*m +20*n );
                        }
                    }
                }
            }
        }
    }
    se.erase(0);
    cout<<"Total="<<se.size();
    return 0;
}