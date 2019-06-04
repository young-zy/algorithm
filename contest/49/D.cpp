#include<bits/stdc++.h>
using namespace std;

int r,k;
int pic[200][200];
int idx[200][200]={0};
int flag[200][200]={0};
int cnt=1;
int v[200]={0};

void dfs(int m,int n,int cnt){
	if(m<0||m>=r||n<0||n>=r) return;
	idx[m][n]=1;
	if(pic[m+1][n]==0&&idx[m+1][n]==0){
		flag[m+1][n]=cnt;
		dfs(m+1,n,cnt);
	}
	if(pic[m][n+1]==0&&idx[m][n+1]==0){
		flag[m][n+1]=cnt;
		dfs(m,n+1,cnt);
	}
	if(pic[m-1][n]==0&&idx[m-1][n]==0){
		flag[m-1][n]=cnt;
		dfs(m-1,n,cnt);
	}
	if(pic[m][n-1]==0&&idx[m][n-1]==0){
		flag[m][n-1]=cnt;
		dfs(m,n-1,cnt);
	}
}

int main(){
	cin>>r>>k;
	memset(idx,0,sizeof(idx));
	memset(flag,0,sizeof(flag));
	memset(v,0,sizeof(v));
	for(int i=0;i<r;i++){
		for(int j=0;j<r;j++){
			cin>>pic[i][j];
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<r;j++){
			if(idx[i][j]==0&&pic[i][j]==0){
				flag[i][j]=cnt;
				dfs(i,j,cnt);
				cnt++;
			} 		
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<r;j++){
			if(i==0||i==r-1||j==0||j==r-1||pic[i][j]==1){
				v[flag[i][j]]=1;
			}
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<r;j++){
			if(flag[i][j]&&v[flag[i][j]]==0){
				pic[i][j]=k;
			}
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<r;j++){
			if(j==r-1){
                cout<<pic[i][j];
            }else{
                cout<<pic[i][j]<<" ";
            } 
		}
		if(i<r-1){
            cout<<endl;
        } 
	}
	return 0;;
}