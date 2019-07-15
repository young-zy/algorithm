#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int t;
	cin>>t;
	for(int te = 0; te < t;te++){
		int a,b;
		cin>>a>>b;
		long long count = 0;
		while(a != b){
			if(a > b){
				swap(a,b);
			}
			b>>=1;
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
