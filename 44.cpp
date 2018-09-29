#include<bits/stdc++.h>

using namespace std;



int main(){
    int N;
    scanf("%d",&N);
    char a[2*N][2*N];
    int temp;
    fflush(stdin);
    for(int i = 0; i< 2*N; i++){
        for(int j = 0; j<2*N;j++){
            scanf("%c ", &a[i][j],&temp);
        }
    }
    int K;
    scanf("%d",&K);
    int count = 0;
    int i;
    for(i = 0;i<K;i++){
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(a[x1-1][y1-1] == a[x2-1][y2-1]){
            if(a[x1-1][y1-1]=='*'){
                printf("Uh-oh");
                count++;
                continue;
            }
            a[x1-1][y1-1] = '*';
            a[x2-1][y2-1] = '*';
            int starcount = 0;
            for(int j = 0;j<2*N;j++){
                for(int k = 0;k<2*N;k++){
                    if(a[j][k] == '*' ){
                        starcount ++;
                    }
                    if(starcount == 4*N*N){
                        printf("Congratulations!");
                        return 0;
                    }
                }
            }
            for(int j = 0;j<2*N;j++){
                for(int k = 0;k<2*N;k++){
                    printf("%c",a[j][k]);
                    if(k != 2*N-1){
                        printf(" ");
                    }
                }
                if(j != 2*N-1){
                    printf("\n");
                }
            }
        }else{
            printf("Uh-oh");
            count++;
        }
        if(count == 3 || (i == K)){
            printf("\nGame Over");
            return 0;
        }
    }
    system("pause");
    return 0;
}