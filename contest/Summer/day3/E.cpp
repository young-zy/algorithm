#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long x[2005];
long long y[2005];

int main(int argc, char** argv) {
	int n,m;
	cin>>n>>m;
	for(int i = 0; i<n ; i++){
		cin>>x[i];
	}
	for(int i = 0; i<m ; i++){
		cin>>y[i];
	}
	int sec = 0;
	while(1){
		int flag = 1;
		int xi = 0; 
		int yi = 0;
		while(1){
			if(xi > n || yi > m){
				break;
			}
			if(x[xi] == y[yi]+sec){
				flag = 0;
				break;
			}else if(x[xi] < y[yi]+sec){
				xi++;
			}else{
				yi++;
			}
		}
		if(flag == 0){
			sec++;
		}else{
			break;
		}
	}
	cout<<sec;
	return 0;
}