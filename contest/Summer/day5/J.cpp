#include <bits/stdc++.h>
#define MOD 109
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long fast_pow_mod(long long a, long long b,long long c){
	long long ans = 1;
	a %= c;
	while(b){
		if(b & 1){
			ans = (ans * a) %c;
		}
		a = (a*a) %c;
		b >>= 1;
	}
	return ans;
}


int main(int argc, char** argv) {
	int n,m;
	cin>>n>>m;
	long long ans = 0;
	ans += fast_pow_mod(n-1,m-1,MOD);
	ans = ans * n;
	ans %= MOD;
	cout<<ans; 
	return 0;
}