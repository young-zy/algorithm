#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a[50005];

int main(int argc, char** argv) {
	string s;
	cin>>s;
	long long ans = 0;
	/*a[0] = 0;
	for(int i = 0; i<s.length();i++){
		if(s[i] == 'Q'){
			a[i+1] = a[i] + 1; 
		}else{
			a[i+1] = a[i];
		}
	}
	
	for(int i = 0; i<s.length() ; i++){
		if(s[i] == 'A'){
			ans += (a[i-1] - a[0] ) * (a[s.length()] - a[i+2]);
		}
	}*/
	for(int i = 0; i<s.length() ; i++){
		if(s[i] == 'A'){
			int a = 0;
			int b = 0;
			for(int j = i-2; j>=0;j--){
				if(s[j] == 'Q'){
					a++;
				}
			}
			for(int j = i+2; j<s.length();j++){
				if(s[j] == 'Q'){
					b++;
				}
			}
			ans += a*b;
		}
	}
	cout<<ans;
	return 0;
}