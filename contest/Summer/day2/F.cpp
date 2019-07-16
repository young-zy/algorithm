#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int t;
	cin>>t;
	for(int te = 0; te < t ;te++){
		string s;
		cin>>s;
		int bcount = 0;
		for(int i = 0; i< s.length();i++){
			if(s[i] == 'B'){
				bcount++;
			}
		}
		if(bcount < (int)((s.length()-1)/(double)2+0.9999) || bcount == s.length()-1){
			cout<<"No"<<endl;
		}else{
			cout<<"Yes"<<endl;;
		}
	}
	return 0;
}