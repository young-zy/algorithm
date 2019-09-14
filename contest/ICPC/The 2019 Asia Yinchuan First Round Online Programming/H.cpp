#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[100005];

struct node {
    int hp,atk,nums;
    bool operator < (struct node no) const{
		return this->atk * no.nums > this->nums* no.atk;
	}
};

struct node no[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0;
    scanf("%d",&t);
    long long atksum = 0;
    long long atk = 1;
    long long sum = 0;
    long long ans = 0;
    int time = 0;
    for(int i = 1; i<100005 ; i++){
        if(i > atksum){
            atksum += atk++;
        }
        a[i] = atksum;
    }
    for(int te = 0; te < t ;te++){
        int n;
        cin>>n;
        for(int i = 0; i<n ; i++){
            scanf("%d %d",&no[i].hp,&no[i].atk);
            sum += no[i].atk;
        }
        sort(no,no+n);
        for(int i = 0; i<n ; i++){
            sum -= no[i].atk;
            ans += sum * no[i].nums;
        }
        cout<<ans<<endl;
    }
    return 0;
}