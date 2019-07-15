#include <bits/stdc++.h>
#define for_(i,a,b) for(int i=a;i<b;++i)
#define for__(i,a,b) for(int i=a;i<=b;++i)
#define rof_(i,a,b) for(int i=a;i>b;--i)
#define rof__(i,a,b) for(int i=a;i>=b;--i)
#define ms(a,b) memset((a),(b),sizeof(a))

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int MN = 1e6 + 5;
int t,k,ans;
int a[16];

int main(int argc, char** argv) {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>k;
		int s=ans=0;	//days per week
		for_(i,0,7)
			cin>>a[i],
			s+=a[i];
		if(s==0){
			cout<<"-1\n";
			continue;
		}
		int cnt=0;	//days in the last week
		int min_cnt=20;
		int c=0;
		/*int first1=0;
		rof__(i,6,0)
			if(a[i])
				first1=i;
		for__(i,first1,6){
			if(a[i])
				++c;
			++cnt;
			if(c==k%s || c==s)
				break;
		}*/
		int target=k%s;
		if(!target)
			target=s;
		for__(i,0,6)
			a[i+7]=a[i];
		for__(i,0,13)
			if(a[i]){
				c=0;
				for__(j,i,13)
					if(a[j])
						if(++c==target){
							min_cnt=min(min_cnt,j-i+1);
							break;
						}
			}
			
//		cout<<"K "<<k<<" S "<<s<<" F "<<first1<<" Cnt "<<cnt<<'\n';
		cout<<(k-1)/s*7 + min_cnt <<'\n';
	}
	
	return 0;
}