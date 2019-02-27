#include<bits/stdc++.h>

using namespace std;

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int a[n];
    queue<int> q;
    map<int,int> ma;
    int count = 0;
    if(m == 0){
        printf("%d",n);
        return 0;
    }
    for(int i =0 ; i<n ;i++){
        scanf("%d",&a[i]);
        if(ma[a[i]] == 0){
            if(q.size() == m){
                ma[q.front()] = 0;
                q.pop();
            }
            q.push(a[i]);
            ma[a[i]] = 1;
            count++;
        }
        //printf("%d\n",q.front());
        // for(int i = q.size();i>0;i--){
        //     int temp;
        //     printf("%d ",temp = q.front());
        //     q.pop();
        //     q.push(temp);
        // }
        // printf("\n");
    }
    printf("%d",count);
    system("pause");
    return 0;
}