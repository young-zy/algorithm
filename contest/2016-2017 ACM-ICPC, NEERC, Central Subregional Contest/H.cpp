#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

#define Debug 1

using namespace std;

int a[105],b[105];
int suma1[105],suma2[105],sumb1[105],sumb2[105];
int ina[105],inb[105],outa[105],outb[105];

deque<int> dq[205];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string in = "input.txt";
    string out = "output.txt";
    ifstream infile;
    ofstream outfile;
    int n,m;
    infile.open(in,ios::in|ios::out);
    outfile.open(out,ios::out | ios::trunc);
#if Debug
    cin>>n>>m;
#else
    infile>>n>>m;
#endif
    for(int i = 0; i<n ; i++){
#if Debug
    cin>>a[i];
#else
    infile>>a[i];
#endif
    }
    for(int i = 0; i<m ; i++){
#if Debug
    cin>>b[i];
#else
    infile>>b[i];
#endif
    }
    for(int i = 0; i<n ; i++){
        int a1 = a[i]/1000;
        int a2 = a[i]%1000;
        while(a1){
            suma1[i] += a1%10;
            a1/=10;
        }
        while(a2){
            suma2[i] += a2%10;
            a2/=10;
        }
    }
    for(int i = 0; i<m ; i++){
        int b1 = b[i]/1000;
        int b2 = b[i]%1000;
        while(b1){
            sumb1[i] += b1%10;
            b1/=10;
        }
        while(b2){
            sumb2[i] += b2%10;
            b2/=10;
        }
    }
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m ; j++){
            if(suma1[i] == sumb2[j]){
                dq[i].push_back(j+100);
                outa[i]++;
                inb[j]++;
            }
            if(suma2[i] == sumb1[j]){
                dq[j+100].push_back(i);
                outb[j]++;
                ina[i]++;
            }
        }
    }
    queue<int> qu;
    for(int i = 0; i<n ; i++){
        if(ina[i] == 1 || outa[i] == 1){
            qu.push(i);
        }
    }
    while (!qu.empty()){
        int temp = qu.front();
        qu.pop();
        
    }
    

    return 0;
}