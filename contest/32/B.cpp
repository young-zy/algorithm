#include<bits/stdc++.h>

using namespace std;
int main()
{
    long long n;
    cin >> n;
    if(n<20190001){
        n+=2018;
    }else{
        n = 20192018;
    }
    cout << n << endl;
    return 0;
}