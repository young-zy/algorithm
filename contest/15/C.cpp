#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n;
	scanf("%d",&n);
	int a=0;
	int b = 0;
	for(int i = 0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		if(temp >= 0 ){
			a+=temp;
		}else{
			b+=temp;
		}
	}
	printf("%d",a-b);
	return 0;
}