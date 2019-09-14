#include <bits/stdc++.h>

using namespace std;

deque<int> dq[200005];

int a[200005];
int b[200005];

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int dfs(int nodenum,int last = -1,int step = 0){
	a[nodenum] = step;
	for(int i = 0; i<dq[nodenum].size();i++){
		if(dq[nodenum][i] == last){
			continue;
		}
		dfs(dq[nodenum][i],nodenum,step+1);
	}
}

int dfs2(int nodenum,int last = -1,int step = 0){
	b[nodenum] = step;
	for(int i = 0; i<dq[nodenum].size();i++){
		if(dq[nodenum][i] == last){
			continue;
		}
		dfs2(dq[nodenum][i],nodenum,step+1);
	}
}

int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	for(int i = 0; i<n-1;i++){
		int a,b;
		cin>>a>>b;
		dq[a].push_back(b);
		dq[b].push_back(a);
	}
	dfs(k);
	dfs2(1);
	int ans = 0;
	for(int i = 1; i<=n ;i++){
		if(a[i] < b[i]){
			ans = max(ans,b[i]*2);
		}
	}
	cout<<ans;
	return 0;
}