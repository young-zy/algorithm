#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool is_Prime(int n){
	if(n == 2 || n == 3){
		return true;
	}else if(n % 2 == 0 || n < 2){
		return false;
	}else{
		for(int i = 3; i<=sqrt(n);i++){
			if(n % i == 0){
				return false;
			}	
		}
		return true;
	}
}

int main(int argc, char** argv) {
	/*FILE *fp = fopen("out.txt","w");
	for(int i = 1; i<=1299709;i++){
		if(is_Prime(i)){
			fprintf(fp,"%d,",i);
		}
	}
	fclose(fp);
	*/
	int n;
	cin>>n;
	if(is_Prime(n)){
		cout<<0;
	}else{
		int ans;
		for(int i = n+1;i<=1299709 ;i++){
			if(is_Prime(i)){
				ans = i;
				break;
			}
		}
		for(int i = n-1;i>=3;i--){
			if(is_Prime(i)){
				ans -= i;
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}