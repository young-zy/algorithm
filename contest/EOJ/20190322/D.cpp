#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int sum = fabs(x1-x2)+fabs(y1-y2);
    if(sum % 2 == 1){
        cout<<"Lose";
    }else{
        cout<<"Win";
    }
    // if(fabs(x1-x2>=2)||fabs(y1-y2)>=2){
    //     if(fabs(x1-x2) == 2 && fabs(y1-y2) == 1 || fabs(x1-x2) == 1 && fabs(y1-y2) == 2){
    //         cout<<"Lose";
    //     }else{
    //         cout<<"Win";
    //     }
        
    // }else{
    //     if(x1 == x2 || y1 == y2){
    //         if(fabs(x1-x2) == 1 || fabs(y1-y2) == 1){
    //             cout<<"Lose";
    //         }else{
                
    //         }
    //     }else{
    //         cout<<"Win";
    //     }
    // }
    return 0;
}