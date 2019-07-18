#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a[1005];
int b[1005];

stack<int> st;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int i = 1;
	int flag = 1;
	int start  = 0;
	int end = 0;
	for(int i = 1; i<=n ; i++){
		cin>>a[i];
		if(a[i] != i && start == 0){
			start = i;
			end = a[i];
		}
	}
	for(int i = start ; i<=(end+start)/2;i++){
		if((end + start) % 2 == 0 && i == (end+start)/2){
			break;
		}
		a[i] ^= a[end-i+start];
		a[end-i+start] ^= a[i];
		a[i] ^= a[end-i+start];
	}
	for(int i = 1; i<=n ; i++){
		if(a[i] != i){
			flag = 0;
			break;
		}
	}
	/*
	while(i<=n){
		if(a[i] != i){
			if(flag == 0){
				start = i;
				flag = 1;
			}
			st.push(a[i]);
		}else if(flag == 1 && a[i] == i){
			flag =2;
			end = i-1;
			break;
		}else{
			
		}
		i++;
	}
	if(flag == 1){
		end = n;
	}
	flag = 1;
	for(int i = 1; i<=n ; i++){
		if(i < start){
			b[i] = a[i];
		}else if(i>=start && i <= end){
			b[i] = st.top();
			st.pop();
		}else{
			b[i] = a[i];
		}
		if(b[i] != i){
			flag = 0;
			break;
		}
	}*/
	if(flag == 0){
		cout<<"No";
	}else{
		cout<<start<<" "<<end;
	}
	
	return 0;
}