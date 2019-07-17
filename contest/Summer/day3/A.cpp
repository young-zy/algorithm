#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

stack<long long> st;

int main(int argc, char** argv) {
	string s;
	cin>>s;
	int num = 0;
	st.push(0);
	for(int i = 0; i< s.length();i++){
		if(s[i] == '@'){
			break;
		}
		if(s[i] == '.'){
			st.push(num);
			num = 0;
		}else if(s[i] == '+'){
			long long temp = st.top();
			st.pop();
			temp += st.top();
			st.pop();
			st.push(temp);
		}else if(s[i] == '-'){
			long long temp = st.top();
			st.pop();
			long long temp2 = st.top();
			st.pop();
			temp2 -= temp;
			st.push(temp2);
		}else if(s[i] == '*'){
			long long temp = st.top();
			st.pop();
			temp *= st.top();
			st.pop();
			st.push(temp);
		}else if(s[i] == '/'){
			long long temp = st.top();
			st.pop();
			long long temp2 = st.top();
			st.pop();
			
			temp2 /= temp;
			st.push(temp2);
		}else{
			num *= 10;
			num += s[i]-'0';
		}
	}
	cout<<st.top();
	return 0;
}