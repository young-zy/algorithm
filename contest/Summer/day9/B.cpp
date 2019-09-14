#include <bits/stdc++.h>

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

unsigned long long a[105];

int main(int argc, char** argv) {
	unsigned long long n;
	cin>>n;
	a[2] = 1;
	a[3] = 2;
	a[4] = 4;
	a[5] = 6;
	for(unsigned long long i = 5;i<=n;i++){
		unsigned long long maxnum = 0;
		for(unsigned long long j = 2;j<=i/2;j++){
			maxnum = max(maxnum,max(a[j],j)*max(a[i-j],i-j));
		}
		a[i] = maxnum;
	}
	cout<<a[n];
	return 0;
}