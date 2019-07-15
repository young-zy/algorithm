#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define maxn 30005

using namespace std;

int a[maxn];
int before[maxn];
int num[maxn];

int find(int n){
    if(a[n] == n){
        return n;
    }
    int temp = find(a[n]);
    before[n] += before[a[n]];
    return a[n] = temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i =1 ;i<=maxn;i++){
        a[i] = i;
        num[i] = 1;
    }
    memset(before,0,sizeof(before));
    for(int te = 0; te< t ;te++){
        char ch;
        int i,j;
        cin>>ch>>i>>j;
        int fatheri = find(i);
        int fatherj = find(j);
        if(ch == 'M'){
            if(fatheri == fatherj){
                continue;
            }
            before[fatheri] += num[fatherj];
            a[fatheri] = fatherj;
            num[fatherj] += num[fatheri];
            num[fatheri] = 0;
        }else{
            if(fatheri != fatherj){
                cout<<-1<<endl;
            }else{
                cout<<fabs(before[i]-before[j])-1<<endl;
            }
        }
    }
    return 0;
}