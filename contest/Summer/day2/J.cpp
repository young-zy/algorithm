#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long a[100005];


int main(int argc, char *argv[]) {
	int n,m;
	cin>>n>>m;
	long long add = 0;
	for(int i = 1; i<=n ; i++){
		cin>>a[i];
	}
	for(int i = 0; i<m ; i++){
		int t;
		cin>>t;
		if(t == 1){
			int v;
			long long x;
			cin>>v>>x;
			a[v] = x-add;
		}else if(t == 2){
			long long y;
			cin>>y;
			add += y;
		}else{
			int q;
			cin>>q;
			cout<<a[q]+add<<endl;
		}
	}
	return 0;
}