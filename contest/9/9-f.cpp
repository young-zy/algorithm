#include<cstdio>

#include<algorithm>

using namespace std;

int f[25][25],n,m,t,god[25];

int main(){
	scanf("%d %d %d",&n,&t,&m);
	for(int i=1;i<=n;i++){
        scanf("%d",&god[i]);
    }
	for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            for(int k=0;k<=t;k++){
                if(god[i]>k){
                    f[j+1][t-god[i]]=max(f[j+1][t-god[i]],f[j][k]+1);
                }else{
                    f[j][k-god[i]]=max(f[j][k-god[i]],f[j][k]+1);
                }
            }
        }
    }
	printf("%d",*max_element(f[m],f[m]+t+1));
    return 0;
}
