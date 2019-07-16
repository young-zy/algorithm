#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a[105];
int b[105];

int main(int argc, char *argv[]) {
	int n;
	while(cin>>n){
		for(int i = 0; i<n ; i++){
			cin>>a[i];
		}
		int flag = 1;
		int wait = 3;
		for(int i = 0; i<n ; i++){
			if(a[i] == wait){
				flag = 0;
				break;
			}else{
				wait ^= a[i];
			}
		}
		if(flag == 0){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}