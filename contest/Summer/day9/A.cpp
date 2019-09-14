#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a[200005];

int main(int argc, char** argv) {
	long long n,k;
	cin>>n>>k;
	for(int i = 0; i<n ; i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long mid = n/2;
	int i = mid;
	while(1){
		while(a[i] == a[i+1]){
			i++;
		}
		if(k / (i-mid+1)){
			k -=  i-mid+1;
			a[i]++;
		}else{
			break;
		}
	}
	cout<<a[i];
	return 0;
}