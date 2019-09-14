#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;
	cin>>t;
	long long n;
	for(int i = 0; i<t ;i++){
		cin>>n;
		double ans = 0;
		for(int i = 0; i<n ; i++){
			ans += (double)n/(n-i);
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}