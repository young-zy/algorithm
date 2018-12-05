#include<bits/stdc++.h>

using namespace std;

bool cmp(struct node a,struct node b);

struct node {
    long num;
    char name[17];
    int height;
    int weight;
};

int main(){
    long n;
    scanf("%ld",&n);
    struct node a[n];
    for(int i = 0;i<n;i++){
        scanf("%ld %s %d %d",&a[i].num,&a[i].name,&a[i].height,&a[i].weight);
    }
    sort(a,a+n,cmp);
    int temp = -1;
    for(int i = 0;i<n;i++){
        if(temp == -1){
            printf("%06d %s %d %d",a[i].num,a[i].name,a[i].height,a[i].weight);
            temp++;
        }else if(a[temp].num == a[i].num){
            continue;
        }else{
            temp = i;
            printf("\n");
            printf("%06ld %s %d %d",a[i].num,a[i].name,a[i].height,a[i].weight);
        }
    }
    return 0;
}

bool cmp(struct node a,struct node b){
    if(a.num != b.num){
        return a.num<b.num;
    }
    return a.height>b.height;
}