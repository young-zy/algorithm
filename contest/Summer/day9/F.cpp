#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;
	cin>>t;
	for(int te = 0; te<t;te++){
		string s;
		cin>>s;
		int count = 0;
		while(count < 2100){
			int flag = 0;
			for(int i = 0; i<s.length();i++){
				if(s[i] == 'z'){
					flag = 1;
					break;
				}else if(s[i] == 'y'){
					continue;
				}else{
					s[i]++;
					break;
				}
			}
			if(flag == 1){
				break;
			}
			flag = 0;
			if(s[0]!='z'){
				break;
			}else{
				s[0] = 'a';
			}
			count++;
		}
		cout<<s<<endl;
	}
	return 0;
}