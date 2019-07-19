#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int l[20005];

priority_queue<int,vector<int>, greater<int> > pq;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>l[i];
		pq.push(l[i]);
	}
	long long temp;
	long long ans  = 0;
	while(1){
		temp = pq.top();
		pq.pop();
		if(!pq.empty()){
			temp += pq.top();
			ans += temp;
			pq.pop();
			pq.push(temp);
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
