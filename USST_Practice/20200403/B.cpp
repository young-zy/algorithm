#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

struct node{
    double k,b;
    node(double _x, double _y){
        k = _x;
        b = _y;
    }
};

double points[105][2];
double dist[105][105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    map<node, int> ma;
    double x,y;

    for(int i = 0; i<n ; i++){
        cin>>points[i][0]>>points[i][1];
    }
    for(int i =0 ; i<n-1 ; i++){
        for(int j = i; j<n; j++){
            dist[i][j] = sqrt(pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2));
            dist[j][i] = dist[i][j];
        }
    }
    int flag = 0;
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<n ; j++){
            if(i == j){
                continue;
            }
            for(int k = 0; k<n;k++){
                if(j == k || i == k){
                    continue;
                }
                if(fabs(dist[i][j] - dist[j][k] - dist[i][k]) < DBL_EPSILON){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }
    if(flag){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}