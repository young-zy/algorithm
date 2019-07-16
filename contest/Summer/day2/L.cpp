#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long change(long long num , int a){
	long long ans = 0;
	while(num){
		ans *= 10;
		ans += num % a;
		num /= a;
	}
	return ans;
}

long long intpow(long long a, long long b){
	long long ans = 1;
	while(b--){
		ans *= a;
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int t;
	cin>>t;
	for(int te = 0; te < t ; te++){
		string s;
		cin>>s;
		long long ans = 0;
		for(int i = 0; i< s.length();i++){
			if(s[i] == '1'){
				for(int j = 2; j<=10;j++){
					ans += intpow(j,s.length()-i-1);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}