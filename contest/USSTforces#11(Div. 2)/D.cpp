#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
map<int,int> ma;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    //cout<<0x3f3f3f3<<endl;
    int minnum = INF,maxnum = -INF;
    int temp;
    for(int i = 0; i<n ; i++){
        cin>>temp;
        ma[temp]++;
        minnum = min(minnum,temp);
        maxnum = max(maxnum,temp);
    }
    if(maxnum - minnum < 2){
        cout<<n<<endl;
        for(auto it:ma){
            while(it.second--){
                cout<<it.first<<" ";
            }
        }
        // if(ma.size()==1){
        //     cout<<n%2<<endl;
        //     for(int i = 0; i<n/2;i++){
        //         cout<<minnum-1<<" ";
        //     }
        //     if(n%2){
        //         cout<<minnum<<" ";
        //     }
        //     for(int i = 0; i<n/2;i++){
        //         cout<<minnum+1<<" ";
        //     }
        // }

    }else{
        int midnum = maxnum-1;
        long long min2 = min(ma[minnum],ma[maxnum]);
        int a = n-min2*2;
        int b = n-(ma[midnum]/2)*2;
        if(b<a){
            cout<<b<<endl;
            ma[minnum] += ma[midnum]/2;
            ma[maxnum] += ma[midnum]/2;
            ma[midnum] -= (ma[midnum]/2)*2;
            for(auto it:ma){
                while(it.second--){
                    cout<<it.first<<" ";
                }
            }
        }else{
            cout<<n-min2*2<<endl;
            if(ma[minnum] <= ma[maxnum]){
                ma[minnum] = 0;
                ma[maxnum] -= min2;
            }else{
                ma[minnum] -= min2;
                ma[maxnum] = 0;
            }
            ma[midnum] += min2*2;
            for(auto it:ma){
                while(it.second--){
                    cout<<it.first<<" ";
                }
            }
        }
        
    }
    return 0;
}