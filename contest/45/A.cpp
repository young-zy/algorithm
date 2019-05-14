#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define inf 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")



using namespace std;

const int maxn=1000;

int n,x,y,ans;
int p[maxn+5][maxn+5];
long long sum=0,hang=inf,lie=inf;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
	for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>p[i][j];
            if(p[i][j]!=-1)
                sum+=p[i][j];
            else
                x=i,y=j;
        }
	}
	int tx,ty;
	if(x>1){
        tx=x-1;
        if(y>1){
            ty=y-1;
        }else{
            ty=y+1;
        }
	}else{
        tx=x+1;
        if(y>1){
            ty=y-1;
        }else{
            ty=y+1;
        }
	}
    p[x][y]=-p[tx][ty]+p[tx][y]+p[x][ty];
    sum+=p[x][y];
    cout<<p[x][y]<<' '<<sum/n;
	return 0;
}