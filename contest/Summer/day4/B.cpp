#include <bits/stdc++.h>
#define MOD 1000000007

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long a[1005][1005];

int b[1005];

using namespace std;

int main(int argc, char** argv) {
	memset(a,0,sizeof(a));
	a[0][0] = 1;
	for(int i = 1; i<=1000 ; i++){
		for(int j = 0;j<=i;j++){
			if(j == 0){
				a[i][j] = 1;
			}else{
				a[i][j] = (a[i-1][j-1] + a[i-1][j]) % MOD;
			}
			//cout<<a[i][j]<<" ";
		}
		//cout<<endl;
	}
	int n,m;
	cin>>n>>m;
	for(int i = 0; i<n ; i++){
		cin>>b[i];
	}
	sort(b,b+n);
	long long ans = 0;
	
	for(int i = 0; i<=(n-m);i++){
		ans  += b[i]*a[n-i-1][m-1];
		ans %= MOD;
	}
	cout<<ans;
	return 0;
}
