#include <bits/stdc++.h>
using namespace std;

int main() {
	int i,i2,i3,i4;
	cin>>i>>i2>>i3>>i4;
	if(i<i2&&i2<i3&&i3<i4)
		cout<<"Fish Rising";
	else if(i>i2&&i2>i3&&i3>i4)
		cout<<"Fish Diving";
	else if(i==i2&&i2==i3&&i3==i4)
		cout<<"Fish At Constant Depth";
	else
		cout<<"No Fish";
	return 0;
}

