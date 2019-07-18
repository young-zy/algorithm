#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//int a[1000];

int main(int argc, char** argv) {
	/*
	for(int i = 1;i <= 100;i++){
		for(int j = 1; j<=2*i;j++){
			a[j] = j;
		}
		int count = 0;
		
		while(1){
			count++;
			int newa[1000];
			for(int j = 1; j<=2*i;j+=2){
				newa[j] = a[i+j/2+1];
			}
			for(int j = 2; j<=2*i;j+=2){
				newa[j] = a[j/2];
			}
			int flag = 0;
			for(int j = 1; j<=2*i;j++){
				a[j] = newa[j];
				if(a[j] != j){
					flag = 1;
				}
			}
			if(flag == 0){
				break;
			}
		}
		cout<<i<<" "<<count<<endl;
	}*/
	int s;
	cin>>s;
	int a = 2;
	int count = 1;
	while(a != 1){
		if(a <= s){
			a <<= 1;
		}else{
			a = ((a-s-1)<<1 )+ 1;
		}
		count++;
	}
	cout<<count;
	return 0;
}