#include <bits/stdc++.h>

using namespace std;

struct node1 {
	int start;
	int end;
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int num, a,l;
	scanf("%d %d %d",&num,&l,&a);
	if(num == 0){
		printf("%d",l/a);
		return 0;
	}
	struct node1 b[num+1];
	b[0].start = 0;
	b[num].end = l;
	for(int i = 0;i<num;i++){
		int sum = 0;
		scanf("%d %d",&b[i].end,&sum);
		b[i+1].start = b[i].end + sum;
	}
	int count = 0;
	for(int i = 0;i<num+1;i++){
		if(b[i].end - b[i].start>=a){
			count += (b[i].end - b[i].start)/a;
		}
	}
	printf("%d",count);
	return 0;
}
