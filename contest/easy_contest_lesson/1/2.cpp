#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int isprime(int a);

int main(int argc, char *argv[]) {
	int l,r;
	scanf("%d %d",&l,&r);
	int count = 0;
	for(int i = 728; i>=0;i--){
		int temp= i;
		int sum = 0;
		while(temp != 0){
			sum += temp %3;
			temp/=3;
		}
		if( (sum<l || sum>r) && isprime(sum) ){
			count++;
			continue;
		}
		if(sum >=l && sum<=r){
			count++;
			continue;
		}
	}
	printf("%d",count);
	return 0;
}

int isprime(int a){
	if(a == 2){
		return 1;
	}else if(a < 2 || a % 2 == 0){
		return 0;
	}else{
		for(int i = 3; i<=sqrt(a);i+=2){
			if(a % i == 0){
				return 0;
			}
		}
		return 1;
	}
}