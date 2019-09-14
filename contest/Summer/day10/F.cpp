#include <bits/stdc++.h>
#define mod 376544743


using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long p[25];

int n,m;

long long ans = 0;

void dfs(long long sum,int count = 0, int num = 0){
	if(count == n){
		return;
	}
	for(int i = count;i<n;i++){
		sum*=p[i];
		if(count % 2){
			ans -= num;
		}else{
			ans += num;
		}
		dfs(num,count+1,num+i);
		num/=p[i];
	}
}

int main(int argc, char** argv) {
	cin>>n>>m;
	for(int i = 0; i<n ; i++){
		cin>>p[i];
		long long temp = m/p[i];
		long long temp1 = p[i]+temp*p[i];
		if(temp % 2){
			temp1 /=2;
		}else{
			temp /=2;
		}
		ans += (((temp % mod) * (temp1 % mod))%mod);
		ans %= mod;
	}
	
	cout<<ans;
	return 0;
}
