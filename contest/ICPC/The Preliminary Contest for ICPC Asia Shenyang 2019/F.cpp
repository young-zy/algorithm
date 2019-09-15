#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;

int n,k,a[maxn];

bool chk(int now){
	priority_queue<int> mx;
	priority_queue<int,vector<int>,greater<int> > mn;
	for(int i=1;i<=n;++i) mx.push(a[i]),mn.push(a[i]);
	int cnt=k;
	while(1){
		if(mx.top()-mn.top()<=now) return 1;
		int a=mx.top(),b=mn.top();
		mx.pop(),mn.pop();
		int t=(a-b-now+1)/2;
        // if((a-b-now+1)%2 != 0){
        //     t++;
        // }
		cnt-=t;
		if(cnt<0) return 0;
		mx.push(a-t),mx.push(b+t),mn.push(a-t),mn.push(b+t);
	}
}

int half(int l,int r){
	while(l<=r){
		int m=l+r>>1;
		if(chk(m)) r=m-1;
		else l=m+1;
	}
	return r;
}

void solve(){
	int ans=half(0,1e9);
	if(!chk(ans)) ans++;
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		solve();
	}
	return 0;
}