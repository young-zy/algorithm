#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

map<char, int> ma;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin>>k;
	string s;
	cin>>s;
	int flag = 1;
	int count = 0;
	for(int i = 0; i<s.length()/2;i++){
		if(s[i] == '?' && s[s.length()-i-1] == '?'){
			count++;			
		}else if(s[i] != '?' && s[s.length()-i-1] == '?'){
			s[s.length()-i-1] = s[i];
			ma[s[i]]+=2;
		}else if(s[i] == '?' && s[s.length()-i-1] != '?'){
			s[i] = s[s.length()-i-1];
			ma[s[i]]+=2;
		}else{
			if(s[i] != s[s.length()-i-1]){
				flag = 0;
				break;
			}else{
				ma[s[i]]+=2;
			}
		}
	}
	if(s.length() % 2){
		if(s[s.length()/2] == '?'){
			count++;
		} else{
			ma[s[s.length()/2]]++;
		}
	}
	if(count + ma.size() < k){
		flag = 0;
	}
	int num = count + ma.size() - k;
	for(int i = 0; i<=s.length()/2;i++){
		if(s[i] == '?' && s[s.length()-i-1] == '?'){
			if(num > 0){
				s[i] = 'a';
				s[s.length()-i-1] = 'a';
				num--;
			}else{
				for(char ch = 'a';ch <= 'z';ch++){
					if(ma[ch] == 0){
						s[i] = ch;
						s[s.length()-i-1] = ch;
						ma[ch] += 2;
						break;
					}
				}
			}
		}
	}
	if(s.length() % 2){
		if(s[s.length()/2] == '?'){
			if(num > 0){
				s[s.length()/2] = 'a';
			}else{
				for(char ch = 'a';ch <= 'z';ch++){
					if(ma[ch] == 0){
						s[s.length()/2] = ch;
						ma[ch] ++;
						break;
					}
				}
			}
		}
	}
	
	
	if(flag == 0){
		cout<<"IMPOSSIBLE";
	}else{
		cout<<s;
	}
	return 0;
}