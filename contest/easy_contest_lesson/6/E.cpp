#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int a[n];
	int max = 0;
	int minplus = 32768;
	for(int i = 0; i<n;i++){
		scanf("%d",&a[i]);
		if(i != 0 && a[i]-a[i-1]>max){
			max = a[i]-a[i-1];
		}
        int temp = a[i]-a[i-1]+a[i-1]-a[i-2];
		if(i>1 && temp < minplus){
			minplus = temp;
		}
	}
	if(minplus <= max){
		printf("%d",max);
	}else{
		printf("%d",minplus);
	}
	return 0;
}