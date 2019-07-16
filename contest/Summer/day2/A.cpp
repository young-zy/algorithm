#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a[1005];

int main(int argc, char *argv[]) {
	int n,t;
	cin>>n>>t;
	for(int i = 0; i<n ; i++){
		cin>>a[i];
	}
	long long count = 0;
	for(int i = 0; i<n ; i++){
		for(int j = 0; j<n ; j++){
			if(i == j){
				continue;
			}
			if(fabs(a[i]-  a[j]) <= t){
				count++;
			}
		}
	}
	cout<<count;
	return 0;
}