#include<bits/stdc++.h>

using namespace std;

int a[100005];

int main(){
    int t = 0;
    cin>>t;
    for(int i = 0 ; i< t ; i++){
        int n,q;
        cin>>n>>q;
        string str;
        cin>>str;
        int casecount = 0;
        map<char,int> ma;
        int llast = 0;
        int rlast = 0;
        for(int j = 0; j< q;j++){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            
            for(int k = l;k<=r;k++){
                ma[str[k]]++;
            }
            int counter = 0;
            for(auto it = ma.begin();it!=ma.end();it++){
                if(it->second % 2 == 1){
                    counter++;
                }
                if(counter >= 2){
                    break;
                }
            }
            if(counter <2){
                casecount++;
            }
        }
        cout<<"Case #"<<i+1<<": "<<casecount<<endl;
    }
    return 0;
}