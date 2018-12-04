#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long n,v,c;


int main(int argc, char** argv) {
	scanf("%ld %ld %ld",&n,&v,&c);
	long a[n],h[n];
	long s;
	for(int i = 0; i< n;i++){
		scanf("%ld",&a[i]);
		s+=a[i];
	}
	for(int i = 0; i< n;i++){
		scanf("%ld",&h[i]);
	}
	double rc = (double)v*a[0]/s;
	if(rc >= c){
		printf("0");
		return 0;
	}else{
        priority_queue<long> pq;
        for(int i = 0; i < n;i++){
            if(h[i] == 0){
                pq.push(a[i]);
            }
        }
		long count = 0;
		while(1){
			long m = pq.top();
            pq.pop();
			s -= m;
			count++;
			rc = (double)v*a[0]/s;
			if(rc >= c){
				printf("%ld",count);
				break;
			}else{
				continue;
			}
		}
	}
    system("pause");
	return 0;
}