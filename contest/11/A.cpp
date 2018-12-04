#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	long n;
	scanf("%ld",&n);
	long max = 0;
	for(long i = 0; i<n;i++){
		long temp;
		scanf("%ld",&temp);
		if(temp > max){
			max = temp;
		}
	}
	printf("%ld",max);
	return 0;
}