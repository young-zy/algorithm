#include <bits/stdc++.h>

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */




int a[500005];
int temp[500005];

long long _count = 0;

void merge(int l, int r){
	int i = l;
	int mid = (l +r)>>1 ;
	int j = mid+1;
	int k = l;
	while(k <= r){
		if(i > mid){
			temp[k] = a[j];
			j++;
		}else if(j > r){
			temp[k] = a[i];
			i++;
		}else if(a[i] <= a[j]){
			temp[k] = a[i];
			i++;
		}else{
			//_count+= mid-i+1;
			temp[k] = a[j];
			j++;
			_count+=mid-i+1;
		}
		k++;
	}
	for(int k = l ; k<=r;k++){
		a[k] = temp[k];
	}
}

void mesort(int l, int r){
	if(l < r){
		int mid = (l+r)>>1;
		mesort(l,mid);
		mesort(mid+1,r);
	}
	merge(l,r);
}


int main(int argc, char** argv) {
	int n;
	cin>>n;
	for(int i = 0; i<n ; i++){
		cin>>a[i];
	}
	mesort(0,n-1);
	cout<<_count;
	return 0;
}