#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int t;
	cin>>t;
	for(int te =0;te < t ;te++){
		long long l,r,k;
		cin>>l>>r>>k;
		long long ans = 0;
		/*if(k > r){
			ans += r-l+1;
		}else if(k < l){
			ans += (r-l+1);
		}else{
			ans += k-l;
			if(k % 2){
				ans += (r-k+1);
			}
		}*/
		if(k % 2 == 0){
			ans = (r-l+1 - (r+1)/(k+1) + (l)/(k+1));
		}else{
			ans = (r -l +1);
		}
		cout<<ans<<endl;
	}
	return 0;
}