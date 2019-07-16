#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int s[105][105];
int sum[105][105];

int main(int argc, char *argv[]) {
	int n,m,t;
	cin>>n>>m>>t;
	memset(sum,0,sizeof(sum));
	for(int i = 0; i<n ; i++){
		for(int j = 0; j <m ; j++){
			cin>>s[i][j];
			sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + s[i][j];
		}
	}
	int maxsum = -INF;
	for(int i = 1; i<=10;i++ ){
		if(i > n){
			break;
		}
		for(int j = 1; j<=10;j++){//枚举套环大小 
			if(j >m){
				break;
			}
			for(int k = i; k <= n;k++){
				for(int l = j;l <= m ;l++){
					int sumnum = sum[k][l] - sum[k][l-j] - sum[k-i][l] + sum[k-i][l-j];
					sumnum -= i*j*t;
					maxsum = max(maxsum,sumnum);
				}
			}
		}
	}
	if(maxsum < 0){
		maxsum = 0;
	}
	cout<<maxsum;
	return 0;
}