#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string s;
	cin>>s;
	long long ans = 1;
	long long count = 0;
	for(int i = 0; i<s.length();i++){
		if(s[i] != 'a'){
			if(s[i] != 'b'){
				s.erase(i,1);
				i--;
			}else{
				if(i>0 &&s[i-1] == 'b'){
					s.erase(i,1);
					i--;
				}
			}
		}else{
			count++;
		}
	}
	long long _count = count;
	int start = 0;
	for(int i = 0; i< s.length();i++){
		if(s[i] == 'b'){
			count = i-start;
			ans *= (count+1);
			ans %= mod;
			start = i+1;
		}
	}
	if(s[s.length()-1]== 'a'){
		ans *= s.length()-start+1;
		ans %= mod;
	}
	ans--;
	if(ans < 0){
		ans+=mod;
	}
	ans %= mod;
	cout<<ans;
	return 0;
}
