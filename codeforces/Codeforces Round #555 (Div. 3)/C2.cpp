#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

long long n,a[200010],b[200010]={};

int main()
{
	// ios_base::sync_with_stdio(false);
    // cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
    int rs=n-1;
    int ls=0;
    int total=0;

	string x,left="L",right="R";
	while(a[ls]>b[total] || a[rs]>b[total] && ls!=rs){
		if(a[ls]==a[rs]){
			int k=0;
			while(a[ls+k]<a[ls+k+1]&&(ls+k)<rs){
				k++;
			}
			int count=0;
			while(a[rs-count]<a[rs-count-1]&&(rs-count)>ls){
				count++;
			}
			if(count>k){
				total += count;
				for(int i = 0;i <= count;i++){
					x += right;
				}
			}else{
				total += k;
				for(int i=0;i<=k;i++){
					x += left;
				}
			}
			total++;
			break;
		}
		if(a[ls] < a[rs] && a[ls] > b[total]){
			b[total+1]=a[ls];
			ls++;
			total++;
			x+=left;
		}else if(a[rs]>b[total]){
			b[total+1]=a[rs];
			rs--;
			total++;
			x+=right;
		}else if(a[ls]>b[total]){
			b[total+1]=a[ls];
			ls++;
			total++;
			x+=left;
		}
	}
	cout<<total<<endl;
	cout<<x;
    return 0;
}
