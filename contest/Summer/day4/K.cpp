#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

deque<int> dq1,dq2;

int a[1000005];
int minnum[1000005];
int maxnum[1000005];


int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	for(int i = 0; i<n ; i++){
		cin>>a[i];	
	}
	for(int i = 0; i< k ;i++){
		if(dq1.empty()){
			dq1.push_back(i);
		}else if(a[i] < a[dq1.back()]){
			dq1.push_back(i);
		}else{
			while(!dq1.empty() && a[i] >= a[dq1.back()])
				dq1.pop_back();
			dq1.push_back(i);
		}
		if(dq2.empty()){
			dq2.push_back(i);
		}else if(a[i] > a[dq2.back()]){
			dq2.push_back(i);
		}else{
			while(!dq2.empty() && a[i] <= a[dq2.back()])
				dq2.pop_back();
			dq2.push_back(i);
		}
	}
	maxnum[k-1] = a[dq1.front()];
	minnum[k-1] = a[dq2.front()];
	for(int i = k ; i< n;i++){
		if(i-k >= dq1.front()){
			dq1.pop_front();
		}
		if(i-k >= dq2.front()){
			dq2.pop_front();
		}
		if(dq1.empty()){
			dq1.push_back(i);
		}else if(a[i] < a[dq1.back()] ){
			dq1.push_back(i);
		}else{
			while(!dq1.empty() && a[i] >= a[dq1.back()])
				dq1.pop_back();
			dq1.push_back(i);
		}
		if(dq2.empty()){
			dq2.push_back(i);
		}else if(a[i] > a[dq2.back()] ){
			dq2.push_back(i);
		}else{
			while(!dq2.empty() && a[i] <= a[dq2.back()])
				dq2.pop_back();
			dq2.push_back(i);
		}
		maxnum[i] = a[dq1.front()];
		minnum[i] = a[dq2.front()];
	}
	for(int i = k-1; i<n ; i++){
		cout<<minnum[i]<<" ";
	}
	cout<<endl;
	for(int i = k-1; i<n ; i++){
		cout<<maxnum[i]<<" ";
	}
	return 0;
}