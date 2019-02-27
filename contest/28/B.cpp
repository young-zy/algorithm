#include<bits/stdc++.h>

using namespace std;

struct node {
    int a,b;
};

bool cmp(struct node a,struct node b){
    if(a.a>b.a){
        return true;
    }
    return false;
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    struct node a[n];
    long ssum = 0;
    for(int i = 0; i<n; i++){
        scanf("%d %d",&a[i].a,&a[i].b);
        ssum += a[i].a*a[i].b;
    }
    if(ssum<m){
        printf("unhappy");
        return 0;
    }
    sort(a,a+n,cmp);
    long sum;
    long count;
    for(int i =0 ;i<n;i++){
        sum += a[i].a*a[i].b;
        if(sum >= m){
            sum -= a[i].a*a[i].b;
            int temp = m-sum;
            count += temp / a[i].a;
            if(temp % a[i].a != 0){
                count++;
            }
            sum = m;
            break;
        }
        count += a[i].b;
    }
    printf("%ld",count);
    system("pause");
    return 0;
}