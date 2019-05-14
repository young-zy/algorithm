#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

int a[200005];
int b[200005];
int c[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
	cin>>n>>m;
	long long count = 0;
	long long count2 = 0;
	for(int i = 0; i< n; i ++){
		int temp;
		for(int j = 0; j< m ;j++){
			cin>>temp;
			a[i] += temp;
			b[j] += temp;
		}
	}
	int flag = 1;
	for(int i = 0; i< n; i ++){
		int count = 0;
		int temp;
		for(int j = 0; j< m ;j++){
			cin>>temp;
			count += temp;
			c[j] += temp;
		}
		if((a[i] & 1)  != (count & 1)){
			flag = 0;
			break;
		}
		
	}
	for(int j = 0; j< m; j++){
		if((b[j] & 1) !=  (c[j] & 1)){
			flag = 0;
		}
	}
	if(flag == 1){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}