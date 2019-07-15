#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int t; 
	cin>>t;
	for(int te = 0; te < t ;te++){
		int k;
		cin>>k;
		int a[7];
		int count =  0;
		for(int i = 0; i< 7 ;i++){
			cin>>a[i];
			count += a[i];
		}
		if(count == 0){
			cout<<-1<<endl;
			continue;
		}
		long long ans = 0;
		int temp;
		long long minans = 0x3f3f3f3f3f3f3f3fll;
		for(int i = 0 ;i < 7;i++){
			ans = 0;
			temp = k;
			for(int j = i ; j <7 && temp > 0;j++){
				if(a[j]){
					temp--;
				}
				ans++;
			}
			ans += 7 * ((temp)/count);
			temp = (temp) % count;
			if(temp == 0 && ans > 7){
				temp += count;
				ans -= 7;
			}
			int j = 0;
			while(temp && j < 7){
				if(a[j]){
					temp--;
				}
				ans++;
				j++;
			}
			minans = min(minans,ans);
		}
		cout<<minans<<endl;
	}
	return 0;
}