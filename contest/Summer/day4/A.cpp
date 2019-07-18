#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	long long n;
	cin>>n;
	long long a,b,c;
	cin>>a>>b>>c;
	long long count = n/a+n/b+n/c;
	count -= n/(a*b/__gcd(a,b)) * 2;
	count -= n/(c*b/__gcd(b,c)) * 2;
	count -= n/(a*c/__gcd(a,c)) * 2;
	count += n/(a*b/__gcd(a,b)*c/__gcd(a*b/__gcd(a,b),c))*4;
	cout<<count;
	return 0;
}
