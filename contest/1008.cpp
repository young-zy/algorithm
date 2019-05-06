#include <bits/stdc++.h>
using namespace std;
#define for_(i,a,b) for(long i=a;i!=b;++i)
map<long,long>m;
vector<long>v;
int cn[3];

int main() {
	long n,t;
	cin>>n;
	for_(i,0,n){
		cin>>t;
		v.push_back(t);
	}
	
	for_(i,1,n){
		m[v[i]-v[i-1]]++;
	}
	map<long,long>::iterator itm=m.begin();
	map<long,long>::iterator edm=m.end();
	long M2=itm->second,M1=itm->first;
	for(++itm;itm!=edm;++itm){
		if(M2<itm->second){
			M1=itm->first;
			M2=itm->second;
		}
	}
	vector<long>::iterator be=v.begin();
	vector<long>::iterator ed=v.end();
	
	vector<long>::iterator it=be,it2=be;
	
	int tcn=0,tcn2=0;
	for(++it2;it2!=ed;++it,++it2){
		if(*it2-*it==M1){
			break;
		}
	}

	vector<long>::iterator it3=it;
	if(it3!=be)
		--it3;
	for(it2=it;it3!=be;--it2,--it3){
		if(*it2-*it3!=M1)
			*it3=*it2-M1;
	}
	
	it3=it;
	if(it3!=ed)
		++it3;
	for(it2=it;it3!=ed;++it2,++it3){
		if(*it3-*it2!=M1)
			*it3=*it2+M1;
	}
	
	it3=be;
	it3++;
	if(*it3-*be!=M1)
		*be=*it3-M1;
	
	it=be;
	cout<<*it;
	for(++it;it!=ed;++it)
		cout<<' '<<*it;
}