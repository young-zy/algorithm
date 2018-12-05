#include<bits/stdc++.h>

using namespace std;

struct node {
    int num;
    char name[11];
    int grade;
};

int main(){
    int n;
    scanf("%d",&n);
    struct node students[n];
    double sum = 0;
    for(int i = 0;i<n;i++){
        scanf("%d",&students[i].num);
        scanf("%s",&students[i].name);
        scanf("%d",&students[i].grade);
        sum += (double)students[i].grade;
    }
    sum /= n;
    printf("%.2lf",sum);
    for(int i = 0;i<n;i++){
        if(students[i].grade<sum){
            printf("\n");
            printf("%s %05d",students[i].name,students[i].num);
        }
    }
    system("pause");
    return 0;
}