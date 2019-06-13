#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node{
	string name;
	int num;
	long long time;
	long long last;
	long long wa[20] = {0};
	int state[20] = {0};
	bool operator < (struct node b) const{
		if(this->num== b.num){
			if(this->time== b.time){
				return this->last < b.last;
			}
			return this->time < b.time;
		}
		return this->num> b.num;
	}
};

struct node2{
	long long x,y,z,t;
	bool operator < (struct node2 b) const{
		return this->t < b.t;
	}
};

struct node2 no[1005];

struct node stu[1000];

int main(int argc, char *argv[]) {
	int n,m;
	cin>>n>>m;
	long long maxtime = 0;
	for(int i = 0; i<n ; i++){
		stu[i].last = INF;
		cin>>stu[i].name;
		string a[m];
		long long b[m];
		for(int j = 0; j<m;j++){
			cin>>a[j];
		}
		for(int j = 0; j<m;j++){
			cin>>b[j];
			maxtime = max(maxtime,b[j]);
		}
		for(int j = 0; j<m;j++){
			stu[i].wa[j]= 0;
			if(a[j][0] == '0'){
				continue;
			}else if(a[j][0] == '+'){
				if(stu[i].last== INF){
					stu[i].last = b[j];
				}else{
					stu[i].last = max(stu[i].last,b[j]);
				}
				stu[i].time += b[j];
				stu[i].num++;
				if(a[j].length() > 1){
					for(int k = 1;k<a[j].length();k++){
						stu[i].time += (pow(10,a[j].length()-1-k))*(a[j][k] - '0')*20;
					}
				}
				stu[i].state[j] = 1;
			}else if(a[j][0] == '-'){
				for(int k = 1 ;k <a[j].length();k++){
					stu[i].wa[j] += (pow(10,a[j].length()-1-k))*(a[j][k] - '0');
				}
			}
		}
	}
	int h;
	cin>>h;
	
	for(int i = 0; i<h;i++){
		cin>>no[i].x>>no[i].y>>no[i].z>>no[i].t;
	}
	sort(no,no+h);
	for(int i = 0; i<h ;i++){
		long long x,y,z,t;
		x = no[i].x;
		y = no[i].y;
		z = no[i].z;
		t = no[i].t;
		//cin>>x>>y>>z>>t;
		x--;
		y--;
		if(stu[x].state[y] == 1){
			continue;
		}
		if(z == 0){
			stu[x].wa[y]++;
		}else{
			stu[x].num++;
			if(stu[x].last == 0x3f3f3f3f){
				stu[x].last = t;
			}else{
				stu[x].last = max(stu[x].last,t);
			}
			stu[x].time += t;
			stu[x].time += stu[x].wa[y]*20;
			stu[x].state[y] = 1;
		}
	}
	sort(stu,stu+n);
	for(int i = 0; i<n ; i++){
		cout<<stu[i].name<<" "<<stu[i].num<<" "<<stu[i].time<<endl;
	}
	return 0;
}

/*
5 4
SOS_Dan
-1 -2 0 +
-1 -1 -1 30
jxcyxctxc
-4 -5 -6 -7
-1 -1 -1 -1
I_AK_IOI
+ + + +
10 110 70 30
Sasaki
-1 -1 -1 -1
-1 -1 -1 -1
Pony.AI
+ + + +
50 60 70 40
10
1 1 1 250
1 2 1 255
1 3 1 257
1 3 0 256
1 3 1 260
2 2 1 299
2 1 1 244
3 1 1 240
4 1 0 241
4 2 0 242

5 4
SOS_Dan
-1 -2 0 +
-1 -1 -1 30
jxcyxctxc
-4 -5 -6 -7
-1 -1 -1 -1
I_AK_IOI
+ + + +
10 110 70 30
Sasaki
-1 -1 -1 -1
-1 -1 -1 -1
Pony.AI
+ + + +
50 60 70 40
10
1 1 1 250
1 2 1 255
1 3 0 256
1 3 1 257
1 3 1 260
2 1 1 244
2 2 1 299
3 1 1 240
4 1 0 241
4 2 0 242


1 4
SOS_Dan
-1 0 0 -1
-1 -1 -1 -1
1
1 1 1 240

*/
