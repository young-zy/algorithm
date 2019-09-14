#include <bits/stdc++.h>
#define for_(i,a,b) for(int i=a;i<b;++i)
#define for__(i,a,b) for(int i=a;i<=b;++i)
#define rof_(i,a,b) for(int i=a;i>b;--i)
#define rof__(i,a,b) for(int i=a;i>=b;--i)
#define ms(a,b) memset((a),(b),sizeof((a)))

using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
 
const int MN = 5e5 + 5;
const int P = 1e3;

int n,m,tot=1;
int w[MN],ans[MN];

pair<int,int> st[MN];	//一维是值，二维是下标

void solve(){
	int n,m; scanf("%d%d",&n,&m);
	int t; for__(i,1,n) scanf("%d",w+i), st[i]= {w[i],i};
	sort(st+1,st+1+n);
	int Mi=st[n].second, r=n;
	rof__(l,n,1){
		int idx= st[l].second;
		while(l<r && w[idx]<=w[st[r].second]+m){
			--r;
			Mi= max(Mi, st[r].second);
		}
		ans[idx]= max(Mi-idx,0) -1;
	}
	printf("%d",ans[1]);
	for__(i,2,n) printf(" %d",ans[i]); 
}

int main(int argc, char** argv) {
//	ios::sync_with_stdio(0);
//	int t= 4e9; cout<<t;
//	int _; scanf("%d",&_); while(_--)
		solve();
	
	return 0;
}