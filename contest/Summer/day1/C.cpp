#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int flag = 0;
	int max= 0; 
	for(int i = 0 ;i< s.length();i++){
		for(int j = s.length(); j>0 ;j--){
			string temp = s.substr(i,j);
			int pos = s.rfind(temp);
			if(pos != string::npos && pos != i && temp.length()>max){
				max = temp.length();
			}
		}
	}
	cout<<max;
	return 0;
}