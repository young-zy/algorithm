#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a[1000005];
long long sum[1000005];

int main(int argc, char *argv[]) {
	int n,k;
	cin>>n>>k;
	sum[0] = 0;
	for(int i = 0;i <n ; i++){
		cin>>a[i];
		sum[i+1] = sum[i] + a[i];
	}
	long long maxsum = -0x3f3f3f3f3f3f3f3f;
	//cout<<maxsum;
	for(int i = k; i<=n ; i++){
		if(sum[i] - sum[i-k] > maxsum){
			maxsum = sum[i] - sum[i-k];
		}
	}
	cout<<maxsum;
	return 0;
}