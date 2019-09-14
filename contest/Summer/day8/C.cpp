#include <bits/stdc++.h>
#define mod 998244353


using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int countb[200005];

int main(int argc, char** argv) {
	int n,m;
	cin>>n>>m;
	long long ans = 0;
	string a,b;
	cin>>a>>b;
	for(int i = 0; i<m ; i++){
		if(b[i] == '1'){
			if(i == 0){
				countb[0] = 1;
			}else{
				countb[i] = countb[i-1]+1;
			}
		}else{
			if(i == 0){
				countb[i] = 0;
			}else{
				countb[i] = countb[i-1];
			}
		}
	}
	long long base = 1;
	for(int i = n-1;i>=0;i--){
		int count = 0;
		if(m-n+i < 0){
			break;
		}
		if(a[i] == '1'){
			count = m-n+i+1;
		}else{
			count = countb[m-n+i];
		}
		if(count < 0){
			count = 0;
		}
		ans += (base*(count%mod))%mod;
		ans %= mod;
		base *= 2;
		base %= mod;
	}
	cout<<ans;
	return 0;
}