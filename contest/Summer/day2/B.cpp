#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	while(cin>>n){
		if(n == 0){
			break;
		}
		cout<<(int)((log(n)/log(3))+0.999999)<<endl;
		//cout<<(int)((log10(n)/log10(2))+0.0000000001)<<endl;
	}
	return 0;
}