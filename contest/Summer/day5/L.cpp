#include <bits/stdc++.h>

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

unsigned long long a[10000][10];

int main(int argc, char** argv) {
	long long n,m;
	scanf("%lld %lld",&n,&m);
	for(int i = 0; i<=n ; i++){
		a[0][i] = 1;
		a[i][0] = 1;
	}
	for(int  i =1 ;i<= n;i++){
		for(int j =1;j<=m;j++){
			a[i][j] = a[i-1][j] + a[i][j-1];
			//cout<<a[i][j]<<" ";
		}
		//cout<<endl;
	}
	cout<<a[n][m];
	return 0;
}