#include<bits/stdc++.h>

using namespace std;

struct node {
	int a,t;
	int flag;
	bool operator < (struct node no) const{
		return this->a * no.t > this->t* no.a;
	}
};

struct node no[100005];

int main(){
	int n;
	cin>>n;
	int suma = 0;
	int sumt = 0;
	for(int i = 0; i<n ; i++){
		cin>>no[i].t>>no[i].a;
		sumt += no[i].t;
		suma += no[i].a;
		//no[i].flag = 0;
	}
	long long ans = 0;
	/*
	while(suma){
		int minnum = 0x3f3f3f3f;
		int minindex = -1;
		for(int i  =0; i<n ; i++){
			if(no[i].flag){
				continue;
			}
			long long temp = (suma-no[i].a)*no[i].t;
			if(temp < minnum){
				minindex = i;
				minnum = temp;
			}
		}
		ans += minnum;
		suma -= no[minindex].a;
		sumt -= no[minindex].t;
		no[minindex].flag = 1;
	}
	*/
	sort(no,no+n);
	for(int i =0; i<n ; i++){
		suma -= no[i].a;
		ans += suma * no[i].t;
	}
	cout<<ans;
	return 0;
}