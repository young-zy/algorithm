#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char ch;

int main() {
	string a;
	int _11_1 = 0;
	int _11_2 = 0;
	int _21_1 = 0;
	int _21_2 = 0;
	while(1){
		ch = getchar();
		if(ch == '\n'){
			continue;
		}
		if(ch == 'E'){
			a += ch;
			printf("%d:%d",_11_1,_11_2);	
			break;
		}
		if(ch == 'W'){
			_11_1++;
		}
		if(ch == 'L'){
			_11_2++;
		}
		a+=ch;
		if(_11_1 >= 11 && _11_1 - _11_2 >= 2 || _11_2 >= 11 && _11_2 - _11_1 >= 2){
			printf("%d:%d\n",_11_1,_11_2);
			_11_1 = 0;
			_11_2 = 0;
		}
	}
	printf("\n\n");
	int i = 0;
	while(1){
		ch = a[i];
		if(ch == '\n'){
			continue;
		}
		if(ch == 'E'){
			printf("%d:%d",_21_1,_21_2);
			break;
		}
		if(ch == 'W'){
			_21_1++;
		}
		if(ch == 'L'){
			_21_2++;
		}
		if(_21_1 >= 21 && _21_1 - _21_2 >= 2 || _21_2 >= 21 && _21_2 - _21_1 >= 2){
			printf("%d:%d\n",_21_1,_21_2);
			_21_1 = 0;
			_21_2 = 0;
		}
		i++;
	}
	return 0;
}