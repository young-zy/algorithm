#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int m[1005],t[1005];
int dp[1005][1005];

int main(int argc, char *argv[]) {
	int n,s,_k;
	cin>>n>>s>>_k;
	for(int i = 0; i<n ; i++){
		cin>>m[i]>>t[i];
	}
	memset(dp,0,sizeof(dp));
	dp[0][0] = 0;
	for(int i = 0; i<n ; i++){
		for(int j = s; j >= m[i] ; j--){
			for(int k = _k; k >= t[i];k--){
				dp[j][k] = max(dp[j][k],dp[j-m[i]][k-t[i]]+1);
			}
		}
	}
	cout<<dp[s][_k];
	return 0;
}