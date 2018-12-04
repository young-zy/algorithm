#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int nums;
	scanf("%d",&nums);
	for(int i = 0; i< nums;i++){
		unsigned long long s,a,b,c;
		scanf("%llu %llu %llu %llu",&s,&a,&b,&c);
		if(c == 0){
			printf("INF\n");
			continue;
		}
		unsigned long long count = s/c;
		count += (count / a) * b;
		printf("%llu\n",count);
	}
	return 0;
}