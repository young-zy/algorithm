#include <bits/stdc++.h>

using namespace std;

long long a[500000];

int main(){
	priority_queue<long long> pq;
	long n;
	long long x,y;
	scanf("%ld %lld %lld",&n,&x,&y);
	if(x == 0 && y == 0){
		printf("-1");
		return 0;
	}
	for(long i = 0;i < n;i++){
		scanf("%lld",&a[i]);
		pq.push(a[i]);
	}
    if(y == 0){
		long long count = pq.top()/x;
		if(fabs(count - (double)pq.top()/x)){
			count++;
		}
        printf("%lld",count);
        return 0;
    }
	if(x == 0){
		long long count = 0;
		for(long i = 0; i<n;i++){
			long temp = a[i]/y;
			count += temp;
			double flag = fabs(temp - (double)a[i]/y);
			if(flag > pow(10,-3) ){
				count++;
			}
		}
		printf("%lld",count);
		return 0;
	}
	long damage = 0;
	long long count = 0;
	while(1){
		if(pq.top() <= damage){
			break;
		}
		damage += x;
		count++;
		long long temp = pq.top();
		pq.pop();
		temp -= y;
		pq.push(temp);
	}
	
	printf("%lld",count);
	return 0;
}