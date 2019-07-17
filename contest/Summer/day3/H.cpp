#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

string s[10005];


map<long long, long long> ma;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int maxlength = -1;
	long long ans = -1;
	for(int i = 0; i<n ; i++){
		cin>>s[i];
		long long start = 1;
		for(int j = 0; j < s[i].length();j++ ){
			if(s[i][j] == '0'){
				start <<= 1ll;
			}else{
				start = ((start << 1 )| 1);
			}
			ma[start]++;
			ans = max(ans,ma[start] * (j+1) );
		}
	}
	cout<<ans;
	return 0;
}