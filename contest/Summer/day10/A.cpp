#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

string s[105];

struct node {
	int x;
	int y;
	node(int _x,int _y){
		x = _x;
		y = _y;
	}
};

char ch[105][105];

queue<struct node> qu;

stack<struct node> st;

int main(int argc, char** argv) {
	int n,m;
	cin>>n>>m;
	int startx,starty,endx,endy;
	
	for(int i = 0; i<n ; i++){
		for(int j = 0; j<m;j++){
			scanf(" %c",&ch[i][j]);
			if(ch[i][j] == 'S'){
				startx = i;
				starty = j;
			}else if(ch[i][j] == 'G'){
				endx = i;
				endy = j;
			}else if(ch[i][j] == 'N'){
				
			}else{
				ch[i][j] = '.';
			}
		}
	}
	qu.push(node(startx,starty));
	ch[startx][starty] = 0;
	while(!qu.empty()){
		struct node temp = qu.front();
		qu.pop();
		int step = ch[temp.x][temp.y];
		if(temp.x > 0 && (ch[temp.x-1][temp.y] == '.' || ch[temp.x-1][temp.y] == 'G')){
			if(ch[temp.x-1][temp.y] == 'G'){
				ch[temp.x-1][temp.y] = step+1;
				break;
			}
			ch[temp.x-1][temp.y] = step+1;
			qu.push(node(temp.x-1,temp.y));
		}
		if(temp.x < n-1 && (ch[temp.x+1][temp.y] == '.' || ch[temp.x+1][temp.y] == 'G')){
			if(ch[temp.x+1][temp.y] == 'G'){
				ch[temp.x+1][temp.y] = step+1;
				break;
			}
			ch[temp.x+1][temp.y] = step+1;
			qu.push(node(temp.x+1,temp.y));
		}
		if(temp.y > 0 && (ch[temp.x][temp.y-1] == '.' || ch[temp.x][temp.y-1] == 'G')){
			if(ch[temp.x][temp.y-1] == 'G'){
				ch[temp.x][temp.y+1] = step+1;
				break;
			}
			ch[temp.x][temp.y-1] = step+1;
			qu.push(node(temp.x,temp.y-1));
		}
		if(temp.y < m-1 && (ch[temp.x][temp.y+1] == '.' || ch[temp.x][temp.y+1] == 'G')){
			if(ch[temp.x][temp.y+1] == 'G'){
				ch[temp.x][temp.y+1] = step+1;
				break;
			}
			ch[temp.x][temp.y+1] = step+1;
			qu.push(node(temp.x,temp.y+1));
		}
		
	}
	while(1){
		st.push(node(endx,endy));
		if(endx == startx && endy == starty){
			break;
		}
		if(endx > 0 && ch[endx-1][endy] < ch[endx][endy]){
			endx--;
		}else if(endx < n-1 && ch[endx+1][endy] < ch[endx][endy]){
			endx++;
		}else if(endy>0 && ch[endx][endy-1] < ch[endx][endy]){
			endy--;
		}else{
			endy++;
		}
	}
	cout<<st.size()-1<<endl;
	while(!st.empty()){
		cout<<st.top().x<<" "<<st.top().y<<endl;
		st.pop();	
	}
	return 0;
}