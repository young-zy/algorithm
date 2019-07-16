#include <bits/stdc++.h>
#define maxn 100005
#define INF 0x3f3f3f3f
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node {
	int max;
	int min;
	long long n;
};

long long sum;
int minnum;
int maxnum;

struct node t[maxn * 4];
int a[maxn];

int lc(int n){
	return n << 1;
}
int rc(int n){
	return (n << 1) | 1;
}
int fa(int n){
	return (n >> 1); 
} 

void update(int n){
	if(n == 0){
		return;
	}
	t[n].n   = t[lc(n)].n + t[rc(n)].n;
	t[n].min = min(t[lc(n)].min,t[rc(n)].min);
	t[n].max = max(t[lc(n)].max,t[rc(n)].max);
}

void setnum(int l, int r, int tindex , int num, int index){
	int mid = (l+r)>>1;
	if(index < l || index > r){
		return;
	}
	if(l == r){
		t[tindex].n = num;
		t[tindex].max = num;
		t[tindex].min = num;
	}else if(index > mid){
		setnum(mid+1,r,rc(tindex),num,index);
		update(tindex);
	}else{
		setnum(l,mid,lc(tindex),num,index);
		update(tindex);
	}
}



void query(int l,int r,int tindex,int ll,int rr){
	int mid = (l+r)>>1;
	if(l>=ll && r <= rr){
		sum += t[tindex].n;
		minnum = min(minnum,t[tindex].min);
		maxnum = max(maxnum,t[tindex].max);
		return;
	}else if(ll > r || rr < l){
		return;
	}else{
		if(ll <= mid){
			query(l,mid,lc(tindex),ll,rr);
		}
		if(rr > mid){
			query(mid+1,r,rc(tindex),ll,rr);
		}
	}
}

int main(int argc, char *argv[]) {
	int n,q;
	cin>>n>>q;
	for(int i = 1; i<=n ; i++){
		int temp;
		cin>>temp;
		setnum(1,n,1,temp,i);
	}
	for(int i = 0; i< q;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			minnum = INF;
			maxnum = -INF;
			sum = 0;
			query(1,n,1,b,c);
			cout<<sum - minnum - maxnum<<endl;
		}else{
			setnum(1,n,1,c,b);
		}
	}
	return 0;
}