#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a[30];

int main(int argc, char** argv) {
	int n,m;
	cin>>n>>m;
	int num = 1<<(n-1);
	for(int i = 0; i<n ; i++){
		cin>>a[i];
	}
	long long maxans = -1;
	for(int  i =0; i<num ; i++){
		int count = 0;
		int temp = i;
		while(temp){
			if(temp & 1){
				count ++;
			}
			temp>>=1;
		}
		if(count == m-1){
			long long ans = 1;
			temp = i;
			int index = n-1;
			long long sum = 0;
			while(index >=0){
				sum += a[index--];
				if(temp & 1){
					ans *= sum;
					sum = 0;
				}
				temp >>= 1;
			}
			ans *= sum;
			maxans = max(maxans,ans);
		}else{
			continue;
		}
	}
	cout<<maxans;
	return 0;
}