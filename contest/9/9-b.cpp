#include <bits/stdc++.h>

using namespace std;

int isprime(int a);

int main() {
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 1;i<=n;i++){
		arr[i-1] = i;
	}
	int flag = 0;
	while(1){
		int count = 0;
		if(arr[0]!=1){
			break;
		}
		int * p = arr;
		for(int j = 0;j < n-1;j++){
			if(isprime(*p+*(p+1))){
				count++;
			}else{
				break;
			}
			p++;
		}
		if(isprime(arr[0]+arr[n-1])){
			count++;
		}
		if(count == n){
		    if(flag != 0){
                printf("\n");
            }
			for(int j = 0; j<n;j++){
				if(j != 0){
					printf(" ");
				}
				printf("%d",arr[j]);
				flag++;
			}
		}
		next_permutation(arr,arr+n);
	}
	return 0;
}

int isprime(int a){
	if(a == 1){
		return 0;
	}else if(a == 2){
		return 1;
	}else if(a % 2 == 0){
        return 0;
	}else{
		for(int i = 3; i<= sqrt(a);i++){
			if(a % i == 0){
				return 0;
			}
		}
		return 1;
	}
}