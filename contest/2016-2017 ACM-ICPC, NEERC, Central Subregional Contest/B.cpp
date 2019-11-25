#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define Debug 1

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string in = "input.txt";
    string out = "output.txt";
    ifstream infile;
    ofstream outfile;
    int n;
    infile.open(in,ios::in|ios::out);
    outfile.open(out,ios::out | ios::trunc);
    #if Debug
    cin>>n;
    #elif
    infile>>n;
    #endif
    int a = n/3;
    int b = n*2;
    if(a % 2){
        
    }
    return 0;
}