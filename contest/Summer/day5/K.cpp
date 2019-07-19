#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long a[100][100]; 

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	long long ans;
	memset(a,0,sizeof(a));
	for(int i = 0; i<=25;i++){
		for(int j = 0; j<=25;j++){
			if(j == 1){
				a[i][j] = 1;
			}
			if(i == j){
				a[i][j] = 1;
			}
		}
	}
	for(int i = 1; i<25 ;i++){
		for(int j = 2;j<=i;j++){
			a[i][j] = j * a[i-1][j] + a[i-1][j-1];
			//cout<<a[i][j]<<" ";
		}
		//cout<<endl;
	}
	while(cin>>n>>m){
		cout<<a[n][m]<<endl;
	}
	
	return 0;
}