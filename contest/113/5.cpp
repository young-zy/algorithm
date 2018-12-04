#include<bits/stdc++.h>

int inquene(int * b,int a,int * length);

int queneadd(int *b,int a,int *length);

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int b[100];
    memset(b,-1,sizeof(b));
    int a[n][m];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m ; j++){
            scanf("%d",&a[i][j]);
        }
    }
    int num;
    scanf("%d",&num);
    for(int i = 0;i<num;i++){
        int count = 0;
        int quenelength = 0;
        memset(b,-1,sizeof(b));
        int x,y,d;
        scanf("%d %d %d",&x,&y,&d);
        for(int j = y-1;j-y+1<d;j++){
            int length = 2*(d -j+y-1) -1;
            for(int k = x - (length-1)/2;x + (length-1)/2 -k>=0;k++){
                if(!inquene(b,a[k][j],&quenelength)){
                    count++;
                    queneadd(b,a[k][j],&quenelength);
                    quenelength++;
                }
            }
        }
        printf("%d",count);
        if(i != num-1){
            printf("\n");
        }
    }
    system("pause");
    return 0;
}

int inquene(int * b,int a,int * length){
    for(int i = 0;i<=*length;i++){
        if(a == b[i]){
            return 1;
        }
        return 0;
    }
}

int queneadd(int *b,int a,int *length){
    b[*length] = a;
    return *length;
}